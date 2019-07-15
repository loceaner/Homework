#include <bits/stdc++.h>
#define lowbit(x) x&(-x)
#define N 500011
#define int long long
using namespace std;

int n, ans = 0, a[N], b[N], t[N]; 

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

inline void update(int x){
	for(int i = x; i <= n; i += lowbit(i)){
		t[i]++;
	}
}

inline int query(int x) {
	int ans = 0;
	for(int i = x; i; i -= lowbit(i)) {
		ans += t[i];
	}
	return ans;
}

signed main() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = b[i] = -read();
	}
	stable_sort(b + 1, b + 1 + n);
	for(int i = 1; i <= n; i++) {
		a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
	}
	for(int i = 1; i <= n; i++) {
		ans += query(a[i] - 1);
		update(a[i]);
	}
	cout << ans << '\n';
	return 0;
}
