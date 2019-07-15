#include <bits/stdc++.h>
#define N 50011
#define int long long
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

struct node {
	int l, r;
} b[N];

int n, m;

void find(int l, int r, int now) {
	int mid = (l + r) >> 1;
	if(b[mid].l <= now && now < b[mid].r) {
		cout << mid << "\n";
		return;
	} else if(now == b[mid].r) {
		cout << mid + 1 << '\n';
		return;
	} else if(now < b[mid].l) find(l, mid, now);
	else if(now > b[mid].r) find(mid + 1, r, now);
}

signed main() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++){
		int x = read();
		b[i].l = b[i - 1].r;
		b[i].r = b[i].l + x;
	}
	while(m--) {
		int x = read();
		find(1, n, x);
	}
	return 0;
}
