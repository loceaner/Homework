#include <bits/stdc++.h>
#define int long long
#define N 100011
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c =='-') f = -1; 
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

int n, m, p, sum[N << 2], add[N << 2], mul[N << 2], a[N << 2];

inline void pushup(int rt) {
	sum[rt] = (sum[lson] % p + sum[rson] % p) % p;
} 

void build(int l, int r, int rt) {
	mul[rt] = 1;;
	if(l == r) {
		sum[rt] = a[l];
		mul[rt] = 1;
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, lson);
	build(m + 1, r, rson);
	pushup(rt);
}

inline void pushdown(int l, int r, int rt) {
	int m = (l + r) >> 1;
	sum[lson] = (sum[lson] * mul[rt] + add[rt] * (m - l + 1)) % p; 
	sum[rson] = (sum[rson] * mul[rt] + add[rt] * (r - m)) % p; 
	mul[lson] = (mul[lson] * mul[rt]) % p;
	mul[rson] = (mul[rson] * mul[rt]) % p;
	add[lson] = (add[lson] * mul[rt] + add[rt]) % p;
	add[rson] = (add[rson] * mul[rt] + add[rt]) % p;
	add[rt] = 0, mul[rt] = 1;
	return;
}

void update_sum(int L, int R, int c, int l, int r, int rt) {
	if(L <= l && r <= R) {
		sum[rt] = (sum[rt] + c * (r - l + 1)) % p;
		add[rt] += c;
		return;
	}
	int m = (l + r) >> 1;
	pushdown(l, r, rt);
	if(L <= m) update_sum(L, R, c, l, m, lson);
	if(R > m) update_sum(L, R, c, m + 1, r, rson);
	pushup(rt);
}

void update_mul(int L, int R, int c, int l, int r, int rt) {
	if(L <= l && r <= R) {
		sum[rt] = sum[rt] * c % p;
		add[rt] = add[rt] * c % p;
		mul[rt] = mul[rt] * c % p;
		return;
	}
	int m = (l + r) >> 1;
	pushdown(l, r, rt);
	if(L <= m) update_mul(L, R, c, l, m, lson);
	if(R > m) update_mul(L, R, c, m + 1, r, rson);
	pushup(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) return sum[rt];
	int m = (l + r) >> 1, ans = 0;
	pushdown(l, r, rt);
	if(L <= m) ans += query(L, R, l, m, lson) % p;
	if(R > m) ans += query(L, R, m + 1, r, rson) % p;
	return ans;
}

signed main() {
	n = read(), p = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	build(1, n, 1);
	m = read();
	for(int i = 1; i <= m; i++) {
		int opt = read(), l = read(), r = read();
		if(opt == 1){
			int c = read();
			update_mul(l, r, c, 1, n, 1);
		}else if(opt == 2){
			int c = read();
			update_sum(l, r, c, 1, n, 1);
		}else if(opt == 3){
			cout << query(l, r, 1, n, 1) % p << '\n';
		}
	}
	return 0;
}
