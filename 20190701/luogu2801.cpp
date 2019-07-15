#include <bits/stdc++.h>
#define N 4000011
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

int n, q, minn[N], lazy[N], ans;

void build(int l, int r, int rt) {
	if(l == r) {
		minn[rt] = read();
	} else {
		build(l, mid, lson);
		build(mid + 1, r, rson);
		minn[rt] = min(minn[lson], minn[rson]);
	}
}

void pushdown(int rt) {
	minn[lson] += lazy[rt];
	lazy[lson] += lazy[rt];
	minn[rson] += lazy[rt];
	lazy[rson] += lazy[rt];
	lazy[rt] = 0;
	return;
}

void query(int L, int R, int rt, int l, int r, int k) {
	if(L <= l && r <= R && minn[rt] >= k) {
		ans += r - l + 1;
		return;
	}
	if(l == r) return;
	if(lazy[rt]) pushdown(rt);
	if(L <= mid) query(L, R, lson, l, mid, k);
	if(R > mid) query(L, R, rson, mid + 1, r, k);
}

void update(int L, int R, int rt, int l, int r, int k) {
	if(L <= l && r <= R) {
		minn[rt] += k;
		lazy[rt] += k;
		return;
	}
	if(lazy[rt]) pushdown(rt);
	if(L <= mid) update(L, R, lson, l, mid, k);
	if(R > mid) update(L, R, rson, mid + 1, r, k);
	minn[rt] = min(minn[lson], minn[rson]);
}

char c;
int tx, ty, tz;

int main() {
	n = read(), q = read();
	build(1, n, 1);
	for(int i = 1; i <= q; i++) {
		cin >> c;
		tx = read(), ty = read(), tz = read();
		if(c == 'M') update(tx, ty, 1, 1, n, tz);
		if(c == 'A') {
			query(tx, ty, 1, 1, n, tz);
			cout << ans << '\n';
			ans = 0;
		}
	}
	return 0;
}
