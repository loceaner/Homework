#include <bits/stdc++.h>
#define N 4011
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

int n, m, k, t, dp[N], ans;

struct node {
	int x, y, w;
}a[N];

bool cmp(node a, node b) {
	return a.x < b.x;
}

int ocean() {
	n = read(), m = read(), k = read(), t = read();
	for(int i = 1; i <= k; i++) a[i].x = read(), a[i].y = read(), a[i].w = read();
	stable_sort(a + 1, a + 1 + k, cmp);
	for(int i = 1; i <= k; i++) dp[i] = a[i].w;
	for(int i = 1; i <= k; i++) {
		for(int j = 0; j < i; j++) {
			if(abs(a[j].y - a[i].y) <= t * abs(a[i].x - a[j].x)) {
				dp[i] = max(dp[i], dp[j] + a[i].w);
			}
		}
	}
	for(int i = 1; i <= k; i++) ans = max(ans, dp[i]);
	cout << ans << '\n';
	return 0;
}

int Loceaner = ocean();
int main(){;}
