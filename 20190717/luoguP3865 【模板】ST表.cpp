#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int N = 1000011;
int n, m, a[N], mx[N][30];

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

inline void prepare() {
	for(int i = 1; i <= n; i++) mx[i][0] = a[i];
	for(int j = 1; (1 << j) <= n; j++) {
		for(int i = 1; i <= n; i++) {
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
		}
	}
}

inline int query(int l, int r) {
	int k = 1;
	while((1 << (k + 1)) <= r - l + 1) k++;
	return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}

int main() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	prepare();
	int l, r;
	for(int i = 1; i <= m; i++) {
		l = read(), r = read();
		cout << query(l, r) << '\n';
	}
}
