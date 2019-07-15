#include <bits/stdc++.h>
#define lson rt << 1
#define rson rt << 1 | 1
#define N 1000011
using namespace std;

int t[N],lazy[N];

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

void pushup(int rt) {
	t[rt] = t[lson] + t[rson];
}

void pushdown(int rt,int l, int r) {
	int m = (l + r) >> 1;
	if(!lazy[rt]) return;
	t[lson] += (m - l + 1) * lazy[rt];
	t[rson] += (r - m) * lazy[rt];
	lazy[lson] += lazy[rt];
	lazy[rson] += lazy[rt];
	lazy[rt] = 0;
}

void update(int rt, int L, int R, int l, int r, int c) {
	if(L <= l && r <= R) {
		t[rt] += c * (r - l + 1);
		lazy[rt] += c;
		return;
	}
	pushdown(rt, l, r);
	int m = (l + r) >> 1;
	if(L <= m) update(lson, L, R, l, m, c);
	if(R > m) update(rson, L, R, m + 1, r, c);
	pushup(rt);
}

int query(int rt, int L, int R, int l, int r) {
	if(L <= l && r <= R) return t[rt];
	pushdown(rt, l, r);
	int m = (l + r) >> 1, ans = 0;
	if(L <= m) ans += query(lson, L, R, l, m);
	if(R > m) ans += query(rson, L, R, m + 1, r);
	return ans;
}

int a[N], n, m;

int main() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++)  a[i] = read();
	for(int i = 1; i <= m; i++) {
		int opt = read(), l = read();
		if(opt == 1){
			int r = read(), k = read(), d = read();
			update(1, l, l, 1, n, k);
			if(r != n) update(1, r + 1, r + 1, 1, n, - (k + (r - l) * d));
			if(r > l) update(1, l + 1, r, 1, n, d);
		}
		else {
			cout << a[l] + query(1, 1, l, 1, n) << '\n';
		}
	}
	return 0;
}
