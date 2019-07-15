#include <bits/stdc++.h>
#define N 10011
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

int a[N], n, m;;

int main() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= m; i++) next_permutation(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) cout << a[i] << ' ';
	return 0;
}
