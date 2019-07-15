#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

int u[100011], n, m;

int main() {
	n = read(), m =read();
	for(int i = 1; i <= m; i++) {
		int c = read(), a =read(), b = read();
		if(c == 0) {
			for(int j = a; j <= b; j++) {
				u[j] =! u[j];
			}
		}
		if(c == 1) {
			int total = 0;
			for(int j = a; j <= b; j++) {
				if(u[j]) total++;
			}
			cout << total << '\n';
		}
	}
	return 0;
}
