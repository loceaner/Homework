#include <iostream>
#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

int n, ans, a1, a0, b1, b0;

int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

ll lcm(int a, int b) {return (ll)a * b / gcd(a, b);}

void cal(int x) {
	if(gcd(x, a0) == a1) {
		if(lcm(x, b0)== b1) {
			ans++;
		}
	}
}

int main() {
	n = read();
	while(n--) {
		ans = 0;
		a0 = read(), a1 = read(), b0 = read(), b1 = read();
		for(int i = 1; i <= sqrt(b1); i++) {
			if(b1 % i == 0) {
				cal(i);
				if(i * i != b1) cal(b1 / i);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}