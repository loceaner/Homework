#include <bits/stdc++.h>
#define int long long
#define N 400011
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

int n, m, mod, wl, wr, wv, ans;

struct node {
	int l, r, w, fc, fj;
} a[N];

void pushup(int rt) {
	a[rt].w = (a[lson].w + a[rson].w) % mod;
}

void build(int rt, int l, int r) {
	a[rt].l = l;
	a[rt].r = r;
	a[rt].fj = 0;
	a[rt].fc = 1;
	if(a[rt].l == a[rt].r) {
		a[rt].w = read();
		return;
	}
	int m = (l + r) >> 1;
	build(lson, l, m);
	build(rson, m + 1, r);
	pushup(rt);
}

void pushdown(int rt, int l, int r, int m) {
	a[lson].w *= a[rt].fc;
	a[rson].w *= a[rt].fc;
	a[lson].w += a[rt].fj * (m - l + 1);
	a[rson].w += a[rt].fj * (r - m);
	a[lson].fc *= a[rt].fc;
	a[rson].fc *= a[rt].fc;
	a[lson].fj *= a[rt].fc;
	a[rson].fj *= a[rt].fc;
	a[lson].fj += a[rt].fj;
	a[rson].fj += a[rt].fj;
	a[rt].fc = 1;
	a[rt].fj = 0;
	a[lson].w %= mod;
	a[lson].fc %= mod;
	a[lson].fj %= mod;
	a[rson].w %= mod;
	a[rson].fc %= mod;
	a[rson].fj %= mod;
}

void add(int rt, int l, int r,int v) {
	if(a[rt].l > r || a[rt].r < l) return;
	if(l <= a[rt].l && a[rt].r <= r) {
		a[rt].w = (a[rt].w + v * (a[rt].r - a[rt].l + 1)) % mod;
		a[rt].fj = (a[rt].fj + v) % mod;
		return;
	}
	int m = (a[rt].l + a[rt].r) >> 1;
	pushdown(rt, a[rt].l, a[rt].r, m);
	add(lson, l, r, v);
	add(rson, l, r, v);
	pushup(rt);
}

void mul(int rt, int l, int r, int v) {
	if(a[rt].l > r || a[rt].r < l) return;
	if(l <= a[rt].l && a[rt].r <= r) {
		a[rt].w *= v % mod;
		a[rt].fc *= v % mod;
		a[rt].fj *= v % mod;
		return;
	}
	int m = (a[rt].l + a[rt].r) >> 1;
	pushdown(rt, a[rt].l, a[rt].r, m);
	mul(lson, l, r, v);
	mul(rson, l, r, v);
	pushup(rt);
}

void sum(int rt, int l, int r) {
	if(a[rt].l > r || a[rt].r < l) return;
	if(l <= a[rt].l && a[rt].r <= r) {
		ans = (ans + a[rt].w) % mod;
		return;
	}
	int m = (a[rt].l + a[rt].r) >> 1;
	pushdown(rt, a[rt].l, a[rt].r, m);
	sum(lson, l, r);
	sum(rson, l, r);
}

signed main() {
	n = read(), m = read(), mod = read();
	build(1, 1, n);
	for(int i = 1; i <= m; i ++) {
		int p = read();
		if(p ==1) {
			wl = read(), wr = read(), wv = read();
			mul(1, wl, wr, wv);
		} else if(p == 2) {
			wl = read(), wr = read(), wv = read();
			add(1, wl, wr, wv);
		} else if(p ==3) {
			wl = read(), wr = read();
			sum(1, wl, wr);
			cout << ans % mod <<'\n';
			ans = 0;
		}
	}
	return 0;
}
