#include <bits/stdc++.h>
#define MOD 1000000007
#define N 5011
#define C(i) ((1LL * i * (i - 1) / 2) % MOD)
using namespace std;

int n, b[N], maxn;
long long ans;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

int main() {
	n = read();
	int x;
	for(int i = 1; i <= n; i++) {
		x = read();
		b[x]++;
		maxn = max(maxn, x);
	}
	for(int i = 1; i <= maxn; i++) {
		for(int j = i; j <= maxn; j++) {
			if(i + j > maxn) break;
			if(i == j) ans = (ans + 1LL * C(b[i]) * C(b[i + j]) % MOD) % MOD;
			else if(b[i] >= 1 && b[j] >= 1 && b[i + j] >= 2){
				ans = (ans + (1LL * b[i] * b[j] * C(b[i + j])) % MOD) % MOD;
			}
		}
	}
	cout << ans << '\n'; 
}