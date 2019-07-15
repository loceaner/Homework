#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
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
	int u, v;
	double w;
} a[N * 100];

int n, fa[N], cnt, k, l;
int x[N], y[N];

void add(int u, int v, double w) {
	a[++cnt].u = u;
	a[cnt].v = v;
	a[cnt].w = w;
}

bool cmp(node a, node b) {
	return a.w < b.w;
}

int find(int p) {
	if(fa[p] == p) return p;
	return fa[p] = find(fa[p]);
}

int main() {
	n = read(), k = read();
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= n; i++) x[i] = read(), y[i] = read();
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			double s = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
			add(i, j, s);
		}
	}
	stable_sort(a + 1, a + cnt + 1, cmp);
	for(int i = 1; i <= cnt; i++) {
		int u = find(a[i].u);
		int v = find(a[i].v);
		if(u == v) continue;
		fa[u] = v;
		l++;
		if(l == n - k + 1) {
			printf("%.2lf", a[i].w);
			return 0;
		}
	}
	return 0;
}
