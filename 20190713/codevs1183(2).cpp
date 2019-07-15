#include <bits/stdc++.h>
#define N 111
using namespace std;

int p[N][N], t[N][N], vis[N * N], tim[N * N], dis[N * N], q[N * N];
int n;
double f[N][N];
int head = 0, tail = 0;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1; 
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

int spfa(int s) {
	memset(vis, false, sizeof(vis));
	memset(tim, 0, sizeof(tim));
	memset(dis, -0x3f, sizeof(dis));
	memset(q, 0, sizeof(q));
	head = 0, tail = 0;
	dis[s] = 0;
	vis[s] = true;
	q[++tail] = s;
	tim[s]++;
	while(head != tail) {
		int now = q[++head];
		for(int i = 1; i <= n; i++) {
			if(p[now][i] != 0 && dis[i] < dis[now] + f[now][i]) {
				dis[i] = dis[now] + f[now][i];
				if(!vis[i]) {
					tim[i]++;
					q[++tail] = i;
					vis[i] = true;
					if(tim[i] > n) return true;
				}
			}
		}
		vis[now] = false;
	}
	if(dis[n] > 0) return true;
	return false;
}

int check(double x) {
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			f[i][j] = p[i][j] - x * t[i][j];
		}
	}
	if(spfa(1)) return 1;
	return 0;
}

int main() {
	n = read();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			p[i][j] = read();
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			t[i][j] = read();
		}
	}
	double eps = 1e-4;
	double l = 0,  r = 1000001;
	while(r - l > eps) {
		double mid = (l + r) / 2;
		if(check(mid)) l = mid;
		else r = mid;
	}
	printf("%.3lf", l);
}
