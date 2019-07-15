#include <bits/stdc++.h>
#define N 4011
using namespace std;

int a[N][N], f[N][N], q[N];
int n, m, k, t;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

inline void work(int i) {
	int l = 0, r = 0;
	for(int j = 1; j <= m; j++) {
		while(l < r && f[i + 1][q[r - 1]] < f[i + 1][j]) r--;
		q[r++] = j;
		while(l < r && q[l] < j - t)l++;
		f[i][j] = f[i + 1][q[l]];
	}
	l = 0, r = 0;
	for(int j = m; j >= 1; j--) {
		while(l < r && f[i + 1][q[r - 1]] < f[i + 1][j]) r--;
		q[r++] = j;
		while(l < r && q[l] > j + t)l++;
		f[i][j] = max(f[i][j], f[i + 1][q[l]]);
	}
	for(int j = 1; j <= m; j++) f[i][j] += a[i][j];
}

int main() {
	n = read(), m = read(), k = read(), t = read();
	for(int i = 1, u, v, w; i <= k; i++) {
		u = read(), v = read(), w = read();
		a[u][v] = w;
	}
	for(int i = 1; i <= m; i++) f[n][i] = a[n][i];
	for(int i = n - 1; i > 0; i--) work(i);
	int ans = -1;
	for(int j = 1; j <= m; j++) ans = max(ans, f[1][j]);
	cout << ans << '\n';
	return 0;
}
