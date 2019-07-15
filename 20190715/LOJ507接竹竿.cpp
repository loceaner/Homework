#include <bits/stdc++.h>
#define N 1000011
#define int long long
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

int lc[N], dp[N], to[N];
int n, k, x;
int sum[N];

signed main() {
	n = read(), k = read();
	for(int i = 1; i <= n; i++) {
		x = read();
		to[i] = lc[x];
		lc[x] = i;
	}
	for(int i = 1; i <= n; i++) {
		x = read();
		sum[i] = sum[i - 1] + x;
	}
	for(int i = 1; i <= n; i++) {
		dp[i] = dp[i-1];
		if(to[i]) dp[i] = max(dp[i], max(dp[to[i]] + sum[i] - sum[to[i]], dp[to[i] - 1] + sum[i] - sum[to[i] - 1]));
	}
	cout << dp[n] << '\n';
	return 0;
}
