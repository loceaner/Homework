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
	int h, l, r, id, ansl, ansr;
} v[N];

int n;

int cmp(node a, node b) {
	if(a.h == b.h) return a.l < b.l;
	return a.h > b.h;
}

int cmp1(node a, node b) {
	return a.id < b.id;
}

int main() {
	n = read();
	for(int i = 1; i <= n; i++) {
		v[i].h = read(), v[i].l = read(), v[i].r = read();
		v[i].id = i;
	}
	sort(v + 1, v + 1 + n, cmp);
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(v[i].ansl && v[i].ansr) break;
			if(!v[i].ansl && v[j].l < v[i].l && v[j].r > v[i].l) v[i].ansl = v[j].id;
			if(!v[i].ansr && v[j].l < v[i].r && v[j].r > v[i].r) v[i].ansr = v[j].id;
		}
	}
	sort(v + 1, v + 1 + n, cmp1);
	for(int i =1; i <= n; i++) {
		cout << v[i].ansl  << ' ' << v[i].ansr << '\n';
	}
	return 0;
}
