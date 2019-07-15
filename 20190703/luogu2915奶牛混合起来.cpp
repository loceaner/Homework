#include <bits/stdc++.h>
#define N 20
#define M 1 << 16
#define int long long
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

int n, k, a[N], f[M][N];
bool vis[N];

int dfs(int sta, int cnt, int pre) {
	if(cnt == n) {return f[sta][pre] = 1;}
	if(f[sta][pre] != -1) return f[sta][pre];
	int res = 0;
	for(int i = 1; i <= n; i++) {
		if(!vis[i] && abs(a[i] - a[pre]) > k) {
			vis[i] = 1;
			res += dfs(sta+(1 << (i - 1)), cnt + 1, i);
			vis[i] = 0;
		}
	}
	f[sta][pre] = res;
	return res;
}

signed main() {
	memset(f, -1, sizeof(f));
	n = read(), k = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	a[0] = -4000;
	dfs(0, 0, 0);
	cout << f[0][0] << '\n'; 
}
