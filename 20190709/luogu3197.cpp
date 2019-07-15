#include <bits/stdc++.h>
#define int long long
#define mod 100003
using namespace std;

int power(int a, int b) {
	int res = 1;
	while(b) {
		if(b&1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int n, m ,ans;

signed main() {
	scanf("%lld%lld", &m, &n);
	cout << (power(m, n) % mod - m * power(m - 1, n - 1) % mod + mod) % mod << '\n';
	return 0; 
}