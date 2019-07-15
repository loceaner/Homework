#include<bits/stdc++.h>
#define N 100011
using namespace std;
int n, x, b[N], maxn;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

int work(int p) {
	int ans = 0;
	int o=sqrt(p);
	for(int i = 1 ; i <= sqrt(p); i++) {
		if(p % i == 0) ans += 2;
		if(i == sqrt(p)) {
			if(p % o == 0)
				ans -= 1;
		}
	}
	return ans;
}

int main() {
	n = read();
	for(int i=1; i<=n; i++) {
		x = read();
		b[x]++;
		maxn = max(maxn, x);
	}
	for(int i = 1; i <= maxn; i++) {
		if(b[i] % 2 == 1) {
			cout<< i << " " << work(i) << '\n';
		}
	}
	return 0;
}
