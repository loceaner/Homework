#include <bits/stdc++.h>
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define int long long
#define N 100011
using namespace std;

int n, m;
ll a[N];

struct node {
    ll sum, mx;
} t[N << 2];

inline void Swap(int &x, int &y) {
    x ^= y, y ^= x, x ^= y;
}

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c =='-') f = -1; 
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

inline void pushup(int rt) {
    t[rt].sum = t[lson].sum + t[rson].sum;
    t[rt].mx = max(t[lson].mx, t[rson].mx);
}

void build(int l, int r, int rt) {
    if (l == r) {
        t[rt].sum = t[rt].mx = a[l];
        return ;
    }
    int m = (l + r) >> 1;
    build(l, m, lson);
    build(m + 1, r, rson);
    pushup(rt);
}

void update(int L, int R, int l, int r, int rt) {
    if (l == r) {
        t[rt].sum = sqrt(t[rt].sum);
        t[rt].mx = sqrt(t[rt].mx);
        return ;
    }
    int m = (l + r) >> 1;
    if (L <= m && t[lson].mx > 1) update(L, R, l, m, lson);
    if (R > m && t[rson].mx > 1) update(L, R, m + 1, r, rson);
    pushup(rt);
}

ll query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) return t[rt].sum;
    int m = (l + r) >> 1;
    ll ans = 0;
    if (L <= m) ans += query(L, R, l, m, lson);
    if (R > m) ans += query(L, R, m + 1, r, rson);
    return ans;
}

signed main() {
	n = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    build(1, n, 1);
    m = read();
    for (int i = 1; i <= m; ++i) {
        int k = read(), x = read(), y = read();
        if (x > y) Swap(x, y);
        if (k == 0) update(x, y, 1, n, 1);
        else cout << query(x, y, 1, n, 1) << '\n';
    }
    return 0;
}
