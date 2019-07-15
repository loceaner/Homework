#include <bits/stdc++.h>
#define N 40011
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

int n, phi[N];

void enlur(int n) {
	for(int i = 2; i <= n; i++) phi[i] = i;
	for(int i = 2; i <= n; i++) {
		if(phi[i] == i) {
			for(int j = i; j <= n; j += i) {
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}

int main() {
	n = read();
	if(n == 1) {
		cout << '0';
		return 0;
	}
	enlur(n - 1);
	int ans = 0;
	for(int i = 2; i <= n - 1; i++) {
		ans += phi[i];
	}
	cout << ans * 2 + 3 << '\n';
	return 0;
}
