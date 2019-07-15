#include <bits/stdc++.h>
#define N 100011
#define lson rt << 1
#define rson rt << 1 | 1
#define int long long
using namespace std;

struct node {
	int l, r, minn; 
}t[N << 2];

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

void pushup(int rt) {
	t[rt].minn = min(t[lson].minn, t[rson].minn);
}

void build(int l, int r, int rt) {
	t[rt].l = l, t[rt].r = r;
	if(l == r) {
		t[rt].minn = read();
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, lson), build(m + 1, r, rson);
	pushup(rt);
}

int ask(int l, int r, int rt) {
	if(l <= t[rt].l && t[rt].r <= r ) return t[rt].minn;
	int nowminn = 0x7fffffff;
	if(t[lson].r >= l) nowminn = min(ask(l, r, lson), nowminn);
	if(t[rson].l <= r) nowminn = min(ask(l, r, rson), nowminn);
	return nowminn;
}

int n, m;

signed main() {
	n = read(), m = read();
	build(1, n, 1);
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read();
		cout << ask(x, y, 1) << ' ';
	}
	return 0;
}
