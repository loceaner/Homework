//线段树维护单点修改+区间查询
#include <bits/stdc++.h>
#define N 100011
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;

int d[N], n, m;

struct node {
	int sta,end,len;
} t[N << 2];

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

void build(int l, int r, int rt) {
	t[rt].len = r - l + 1;
	if(l == r) return;
	int m = (l + r) >> 1;
	build(l, m, lson),build(m + 1, r, rson);
}

void update_sta(int L, int c, int l, int r, int rt) {
	if(l == r) {
		t[rt].sta += c;
		return;
	}
	int m = (l + r) >> 1;
	if(L <= m) update_sta(L, c, l, m, lson);
	else update_sta(L, c, m + 1, r, rson);
	t[rt].sta = t[lson].sta + t[rson].sta;
}

void update_end(int L, int c, int l, int r, int rt) {
	if(l == r) {
		t[rt].end += c;
		return;
	}
	int m = (l + r) >> 1;
	if(L <= m) update_end(L, c, l, m, lson);
	else update_end(L, c, m + 1, r, rson);
	t[rt].end = t[lson].end + t[rson].end;
}

int query_sta(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) return t[rt].sta;
	int m = (l + r) >> 1, ans = 0;
	if(L <= m) ans += query_sta(L, R, l, m, lson);
	if(R > m) ans += query_sta(L, R, m + 1, r, rson);
	return ans;
}

int query_end(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) return t[rt].end;
	int m = (l + r) >> 1, ans = 0;
	if(L <= m) ans += query_end(L, R, l, m, lson);
	if(R > m) ans += query_end(L, R, m + 1, r, rson);
	return ans;
}

int main() {
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int q = read(), l = read(), r = read();
		if(q == 1) update_sta(l, 1, 1, n, 1), update_end(r, 1, 1, n, 1);
		else cout << query_sta(1, r, 1, n, 1) - query_end(1, l - 1, 1, n, 1) << '\n';
	}
	return 0;
}
