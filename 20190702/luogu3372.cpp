#include <bits/stdc++.h>
#define N 100011
#define lson rt << 1
#define rson rt << 1 | 1
#define int long long
using namespace std;

int sum[N << 2], lazy[N << 2], n, m;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

inline void pushup(int rt) {
	sum[rt] = sum[lson] + sum[rson];
}

void build(int l, int r, int rt) {
	if(l == r) {
		sum[rt] = read();
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, lson);
	build(m + 1, r, rson);
	pushup(rt);
}

inline void pushdown(int l, int r, int rt) {
	if(!lazy[rt]) return;
	lazy[lson] += lazy[rt];
	lazy[rson] += lazy[rt];
	int m = (l + r) >> 1;
	sum[lson] += (m - l + 1) * lazy[rt];
	sum[rson] += (r - m) * lazy[rt];
	lazy[rt] = 0;
	return;
}

void update(int L, int R, int c, int l, int r, int rt) {
	if(L <= l && r <= R) {
		sum[rt] += c * (r - l + 1);
		lazy[rt] += c;
		return;
	}
	pushdown(l, r, rt);
	int m = (l + r) >> 1;
	if(L <= m) update(L, R, c, l, m, lson);
	if(R > m) update(L, R, c, m + 1, r, rson);
	pushup(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) return sum[rt];
	pushdown(l, r, rt);
	int m = (l + r) >> 1, ans = 0;
	if(L <= m) ans += query(L, R, l, m, lson);
	if(R > m) ans += query(L, R, m + 1, r, rson);
	return ans;
}

signed main() {
	n = read(), m = read();
	build(1, n, 1);
	for(int i = 1; i <= m; i++) {
		int opt = read(), x = read(), y = read();
		if(opt == 1) {
			int k = read();
			update(x, y, k, 1, n, 1);
		}
		if(opt == 2) cout << query(x, y, 1, n, 1) << '\n';
	}
	return 0;
}
