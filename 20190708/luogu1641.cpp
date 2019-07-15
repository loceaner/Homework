#include <bits/stdc++.h>
#define MOD 20100403
#define int long long
using namespace std;

int n, m;
int C(int x, int y) {
	int a = 1;
	for(int i = 2; i <= x; i++) a = (a * i) % MOD;
	int b = 1;
	for(int i = 2; i <= y; i++) b = (b * i) % MOD;
	int c = 1;
	for(int i = 2; i <= x - y; i++) c = (c * i) % MOD;
	b = (b * c) % MOD;
	int d = 1;
	int p = MOD - 2;
	while(p) {
		if(p & 1) d = (d * b) % MOD;
		b = (b * b) % MOD;
		p >>= 1;
	}
	return (a * d) % MOD;
}

signed main() {
	cin >> n >> m;
	cout << (C(n + m, n) - C(n + m, n + 1) + MOD) % MOD;
	return 0;
}