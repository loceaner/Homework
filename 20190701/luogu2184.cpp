//两个树状数组分别维护左括号和右括号
#include <bits/stdc++.h>
#define lowbit(x) x&(-x)
#define N 100111
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

int n, m, a[N], t[N];

inline void add(int l, int r) {
	while(l <= n) {
		a[l]++;
		l += lowbit(l);
	}
	while(r <= n) {
		t[r]++;
		r += lowbit(r);
	}
}

inline int query(int l, int r) {
	int ans1 = 0, ans2 = 0;
	l--;
	while(r > 0){
		ans1 += a[r];
		r -= lowbit(r);
	}
	while(l > 0){
		ans2 += t[l];
		l -= lowbit(l);
	}
	return ans1 - ans2;
}

int main() {
	n = read(), m = read();
	for(int i = 1; i <= m; i++){
		int q, l, r;
		q = read(), l = read(), r = read();
		if(q == 1) add(l, r); 
		if(q == 2) cout << query(l, r) << '\n'; 
	}
	return 0;
}
