#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define mid ((l + r) >> 1)
#define reg register
using namespace std;

const int N = 50011;
int n, m, i, a, b;

struct node {
	int l, r;
	char s[15], ss[15];
} t[N << 2]; 

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

void build(reg int l, reg int r, reg int rt) {
	t[rt].l = l;
	t[rt].r = r;
	if(l == r) {
		scanf("%s", t[rt].s);
		strcpy(t[rt].ss, t[rt].s);
		reg int len = strlen(t[rt].s);
		for(i = 0; i < len; i++) {
			t[rt].s[i] = tolower(t[rt].s[i]);
		}
		return;
	}
	build(l, mid, lson);
	build(mid + 1, r, rson);
	if(strcmp(t[lson].s, t[rson].s) > 0) {
		strcpy(t[rt].s, t[lson].s), strcpy(t[rt].ss, t[lson].ss);
	}
	else strcpy(t[rt].s, t[rson].s), strcpy(t[rt].ss, t[rson].ss);
}

int query(reg int l, reg int r, reg int rt) {
	if(t[rt].l > r || t[rt].r < l) return 0;
	if(l <= t[rt].l && t[rt].r <= r) return rt;
	reg int a = query(l, r, lson), b = query(l, r, rson);
	return strcmp(t[a].s, t[b].s) > 0 ? a : b;
}

int main() {
	n = read(), m = read();
	build(1, n, 1);
	strcpy(t[0].s, "1");
	for(i = 1; i <= m; i++) {
		a = read(), b = read();
		printf("%s\n",t[query(a,b,1)].ss);
	}
	return 0;
}
