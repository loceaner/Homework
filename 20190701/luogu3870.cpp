#include <bits/stdc++.h>
#define lson rt << 1
#define rson rt << 1 | 1
#define N 1000011
using namespace std;

int n, m, x, y, c;

struct node {
	int sum, lazy, len;
} t[N];

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

inline void pushup(int rt) {
	t[rt].sum = t[lson].sum + t[rson].sum;
}

void build(int l, int r, int rt) {
	t[rt].len = r - l + 1;
	if(l == r) {
		t[rt].sum = 0;
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, lson);
	build(m + 1, r, rson);
	pushup(rt);
}

inline void pushdown(int rt) {
	if (t[rt].lazy) {
		t[lson].lazy ^= 1;
		t[rson].lazy ^= 1;
		t[lson].sum = t[lson].len - t[lson].sum;
		t[rson].sum = t[rson].len - t[rson].sum;
		t[rt].lazy = 0;
	}
}

void update(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) {
		t[rt].lazy ^= 1;
		t[rt].sum = t[rt].len - t[rt].sum;
		return;
	}
	int m = (l + r) >> 1;
	pushdown(rt);
	if (L <= m) update(L, R, l, m, lson);
	if (R > m) update(L, R, m + 1, r, rson);
	pushup(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) return t[rt].sum;
	int m = (l + r) >> 1, ans = 0;
	pushdown(rt);
	if (L <= m) ans += query(L, R, l, m, lson);
	if (R > m) ans += query(L, R, m + 1, r, rson);
	return ans;
}

int main(int argc, char const *argv[]) {
	n = read(), m = read();
	build(1, n, 1);
	for (int i = 1; i <= m; ++i) {
		c = read(), x = read(), y = read();
		if (c == 0) update(x, y, 1, n, 1);
		if (c == 1) printf("%d\n", query(x, y, 1, n, 1));
	}
	return 0;
}
