#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1001111;
int n, k, m, d, b[N], p, pre, ans;
struct node {
	int id, wor, tag, bh;
} a[N];

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

bool cmp(node a, node b) {
	return a.wor < b.wor;
}

int erbound(int now) {
	int l = now, r = n, mid, ans = n + 1;
	while(l <= r) {
		mid = (l + r) >> 1;
		if(a[mid].wor > a[now].wor + k) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	for(int i = ans; i <= n; i++) if(!a[i].tag) return i;
	return n + 1;
}

int main() {
	n = read(), m = read(), k = read();
	for(int i = 1; i <= n; i++) a[i].wor = read(), a[i].id = i;
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= n; i++) b[a[i].id] = i;
	p = 1;
	while(d != n) {
		ans++;
		for(int i = p; i <= n; i++) {
			if(!a[i].tag) {
				pre = i;
				p = pre + 1;
				break;
			}
		}
		a[pre].tag = 1;
		d++;
		a[pre].bh = ans;
		while(1) {
			int num = erbound(pre);
			if(num > n) break;
			a[num].bh = ans;
			a[num].tag = 1;
			d++;
			pre = num;
		}
	}
	cout << ans << '\n';
	for(int i = 1; i <= n; i++) {
		cout << a[b[i]].bh << ' ';
	}
	return 0;
}
