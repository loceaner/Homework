#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

ll a = 1, b = 2, c = 6, d = 8;
ll ans, n;

int main() {
	freopen("rakuen.in", "r", stdin);
	freopen("rakuen.out" ,"w", stdout);
	cin >> n;
	int orz = n % 8;
	n /= 8;
	for(ll i = 1; i <= n; i++) {
		ans += a + b + b + c + c + 1 + d;
		a += 8;
		c += 8;
		d = c + 2;
	}
	if(orz == 0) cout << ans %  998244353;
	ans += a;
	if(orz == 1) cout << ans %  998244353;
	a += 8;
	ans += b;
	if(orz == 2) cout << ans %  998244353;
	ans += b;
	if(orz == 3) cout << ans %  998244353;
	ans += c;
	if(orz == 4) cout << ans %  998244353;
	ans += c + 1;
	c += 8;
	if(orz == 5 || orz == 6 || orz == 7) cout << ans %  998244353;
	ans += d;
	d = c + 2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
