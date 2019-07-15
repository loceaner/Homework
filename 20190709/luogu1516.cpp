#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

int x, y, m, n, l, a, b, c, x0, y0, g, tmp;

void exgcd(int a, int b) {
	if(!b) {
		x0 = 1;
		g = a;
		return;
	}
	exgcd(b, a % b);
	tmp = x0;
	x0 = y0;
	y0 = tmp - a / b * y0;
}

signed main() {
	scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l);
	a = n - m;
	b = l;
	c = x - y;
	if(a < 0) a = -a, c = -c;
	exgcd(a, b);
	if(c % g) cout << "Impossible\n";
	else cout << (c / g * x0 % (b / g) + b / g) % (b / g);
	return 0;
}