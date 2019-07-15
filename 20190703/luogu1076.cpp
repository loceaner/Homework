#include <bits/stdc++.h>
#define N 10111 
#define M 1011
using namespace std;

int n, m, sum = 0;
int a[N][M], b[N][M], cnt[N * 10];
int sta;

inline int read() {
	char c = getchar();
	int x = 0, f= 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

int main() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < m; j++) {
			a[i][j] = read(), b[i][j] = read();
			if(a[i][j] == 1 ) cnt[i]++;
		}
	}
	sta = read();
	int ans = b[1][sta];
	int j = sta, i = 1;
	while(i < n) {
		int x, y = 0;
		x= b[i][j] % cnt[i];
		if(x == 0) {
			x = cnt[i];
		}
		while(y + a[i][j] < x) {
			y = y + a[i][j];
			j++;
			if(j == m) j = 0;
		}
		i++;
		ans = ans + b[i][j];
		ans %= 20123;
	}
	cout << ans % 20123 << '\n';
	return 0;
}
