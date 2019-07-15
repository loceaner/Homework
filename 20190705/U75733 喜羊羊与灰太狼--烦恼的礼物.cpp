#include<bits/stdc++.h>
#define N 100011
using namespace std;

int n, m, a[N], l, r;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

bool check(int x) { 
	int cnt = 1, tot = x;
	for(int i = 1; i <= m; i++) {
		if(a[i] <= tot) tot -= a[i];
		else tot = x - a[i], cnt++;
		if(cnt > n) return false;
	}
	return true;
}

int main() {
	m = read(), n = read();
	for(int i = 1; i <= m; i++) {
		a[i] = read();
		if(a[i] > l) l = a[i];
	}
	r=100000001;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(mid == 0) break;
		if(check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n",l);
	return 0;
}

