#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48); 
	return x * f;
}

const int N = 2011;
int n, m, v, e, c[N], d[N];
double ans = INF, k[N], dis[311][311], dp[N][N][2];

int ocean(){
	n = read(), m = read(), v = read(), e = read();
	for(int i = 1; i <= n; i++) c[i] = read();
	for(int i = 1; i <= n; i++) d[i] = read();
	for(int i = 1; i <= n; i++) scanf("%lf", &k[i]);
	for(int i = 1; i <= v; i++) {
		for(int j = 1; j <= v; j++) {
			dis[i][j] = (i == j ? 0 : INF);
		}
	}
	while(e--) {
		int x = read(), y = read(), z = read();
		dis[x][y] = dis[y][x] = min(dis[x][y], double(z));
	}
	for(int k = 1; k <= v; k++) {
		for(int i = 1; i <= v; i++) {
			for(int j = 1; j <= v; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			dp[i][j][0] = dp[i][j][1] = INF;
		}
	}
	dp[1][0][0] = dp[1][1][1] = 0;
	for(int i = 2; i <= n; i++) {
		dp[i][0][0] = dp[i - 1][0][0] + dis[c[i - 1]][c[i]];
		for(int j = 1; j <= min(i, m); j++) {
			dp[i][j][0] = min(dp[i][j][0], 
						  min(dp[i - 1][j][0] + dis[c[i - 1]][c[i]], 
						  dp[i - 1][j][1] + dis[c[i - 1]][c[i]] * (1 - k[i - 1]) + dis[d[i - 1]][c[i]] * k[i - 1]));
			dp[i][j][1] = min(dp[i][j][1], 
						  min(dp[i - 1][j - 1][0] + dis[c[i - 1]][c[i]] * (1 - k[i]) + dis[c[i - 1]][d[i]] * k[i],
						  dp[i - 1][j - 1][1] + 
						  dis[d[i - 1]][d[i]] * k[i - 1] * k[i] + 
						  dis[c[i - 1]][d[i]] * (1 - k[i - 1]) * k[i] + 
						  dis[d[i - 1]][c[i]] * k[i - 1] * (1 - k[i]) + 
						  dis[c[i - 1]][c[i]] * (1 - k[i - 1]) * (1 - k[i])));
		}
	}
	for(int i = 0; i <= m; i++) ans = min(ans, min(dp[n][i][0], dp[n][i][1]));
	printf("%.2lf", ans);
	return 0; 
}

int loceaner = ocean();
int main(){;}
