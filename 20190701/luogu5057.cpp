#include <bits/stdc++.h>
#define N 1000111
#define lowbit(x) x&(-x)
using namespace std;

int n, m, c[N][2];

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

void update(int x, int y, int t) {
	for(; x <= n ; x += lowbit(x)) c[x][t] += y;
}

int getsum(int x, int t) {
	int ans = 0;
	for(; x; x -= lowbit(x)) ans += c[x][t];
	return ans; 
}

int main() {
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int x = read();
		if(x == 1){
			int l = read(), r = read();
			update(l, 1, 0);
			update(r, 1, 1);
		}
		if(x == 2){
			int t = read();
			cout << ((getsum(t, 0) - getsum(t-1, 1))) << '\n';
		}
	}
	return 0;
}
