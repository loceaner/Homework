#include <bits/stdc++.h>
#define N 10011
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

struct node {
	int l, r, next;
	bool operator < (const node b) const{
		return l < b.l;
	}	
} a[N];

int n, k, f[N];

int search(int cur) {
	if(f[cur]) return f[cur];
	int res = 0x7fffffff, limit = 0x7fffffff;
	for(int i = cur + 1; i <= k; i++) {
		if(a[i].l > limit) break;
		else if(a[i].l > a[cur].r) {
			res = min(res, search(i));
			limit = min(limit, a[i].l);
		}
	}
	f[cur] = a[cur].r - a[cur].l + 1;
	if(res != 0x7fffffff) return f[cur] += res;
	else return f[cur];
}

int main() {
	n = read(), k = read();
	a[0].l = 1;
	a[0].r = 0;
	for(int i = 1; i <= k; i++) {
		a[i].l = read();
		a[i].r = read();
		a[i].r += a[i].l -1;
	}
	sort(a + 1, a + k + 1);
	search(0);
	cout << n - f[0] << '\n';
}
