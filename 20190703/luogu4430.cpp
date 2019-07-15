#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

ll m=1, x, mod=9999991;

inline int read() {
	char c = getchar();
	int x = 0, f= 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

signed main() {
	x = read();
	for(int i = 2; i <= x - 1; i++) {
		m = ((m * x) % mod * i) % mod;
	}
	cout << m << '\n';
}
