#include <bits/stdc++.h>
#define int long long
#define N 5011
#define MOD 1000000007
using namespace std;

int C1(int x) {
	return x;
}

int C2(int x) {
	return x * (x - 1) / 2;
}

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

int b[N], n, x, maxn, ans;

signed main() {
	n = read();
	for(int i = 1; i <= n; i++) {
		x = read();
		b[x] ++;
		maxn = max(maxn, x);
	}
	for(int i = 1; i <= maxn; i++) {
		for(int j = 1; j <= i/2; j++) {
			int y = i - j;
			if(y != j) {
				if(b[i] >= 2 && b[j] >= 1 && b[y] >=1)
					ans += (C2(b[i]) % MOD * C1(b[j]) % MOD * C1(b[y]) % MOD) % MOD; 
			}
			else {
				if(b[i] >= 2 && b[j] >= 2)
					ans += (C2(b[i]) % MOD * C2(b[j]) % MOD) % MOD;
			}
			ans %= MOD;
		}
	}
	cout << ans;
	return 0;
}