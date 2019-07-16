#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

long long n,ans;
char a;

long long power(long long a, int b) {
	long long res = 1;
	while(b) {
		if(b & 1) res  = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		if(a == 'B') ans += power(2ll, i);
	}
	cout << ans;
}
