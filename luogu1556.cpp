#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

const int N = 20;
int x[N], y[N], n, ans, vis[N];

int dir(int x1, int y1, int x2, int y2) {
	return x1 == x2 ? int(y1 > y2) : int(x1 > x2) + 2;
}

void dfs(int c, int d, int dep) {
	if(dep == n) {
		if((x[c] == 1000 || y[c] == 1000) && dir(1000, 1000, x[c], y[c]) != d) {
			++ans;
		}
		return;
	}
	vis[c] = 1;
	for(int i = 1; i <= n; i++) {
		if((x[i] == x[c] || y[i] == y[c]) && !vis[i] && dir(x[i], y[i], x[c], y[c]) != d) {
			dfs(i, dir(x[i], y[i], x[c], y[c]), dep + 1);
		}
	}
	vis[c] = 0;
}

int main() {
	n = read();
	for(int i = 1; i <= n; i++) {
		x[i] = read(), y[i] = read();
		x[i] += 1000;
		y[i] += 1000;
	}
	x[0] = y[0] = 1000;
	dfs(0, 4, 0);
	cout << ans  << '\n';
}
