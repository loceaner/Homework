#include <iostream>
#include <cstdio>
#define N 300001
#define M 30
using namespace std;

int tot = 1, t[N * M][2], sum[N * M];
int a[N];

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

inline void insert(int x) {
	int now = 1;
	sum[now]++;
	for(int i = M - 1; i >= 0; i--) {
		if(!t[now][x >> i & 1]) t[now][x >> i & 1] = ++tot;
		now  = t[now][x >> i & 1];
		sum[now]++;
	}
}

inline int find(int x) {
	int now = 1, y = 0;
	sum[now]--;
	for(int i = M - 1; i >= 0; i--) {
		if(sum[t[now][x >> i & 1]]) now = t[now][x >> i & 1];
		else now = t[now][!(x >> i & 1)], y += 1 << i;
		sum[now]--;
	}
	return y;
}

int n, x;

int main() {
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) {
		x = read();
		insert(x);
	}
	for(int i = 1; i <= n; i++) cout << find(a[i]) << ' ';
	return 0;
}
