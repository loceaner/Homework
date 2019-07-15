#include <iostream>
#include <cstdio>
#define N 16
using namespace std;

int n, m, x, y, map[N][N], tot = 0;
char c;
bool vis[N][N];


inline int read() {
	char c = getchar();
	int x = 0, f= 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

void dfs(int x, int y) {
	tot++;
	vis[x][y] = 1;
	if((map[x - 1][y] == map[x][y]) && !vis[x - 1][y]) dfs(x - 1, y);
	if((map[x + 1][y] == map[x][y]) && !vis[x + 1][y]) dfs(x + 1, y);
	if((map[x][y + 1] == map[x][y]) && !vis[x][y + 1]) dfs(x, y + 1);
	if((map[x][y - 1] == map[x][y]) && !vis[x][y - 1]) dfs(x, y - 1);
}

int main() {
	n = read(), m = read(), x = read(), y = read();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> c;
			if(c == 'A') map[i][j] = 1;
			if(c == 'B') map[i][j] = 2;
			if(c == 'C') map[i][j] = 3;
			if(c == 'D') map[i][j] = 4;
		}
	}
	if(!map[x][y]) {
		cout << '0';
		return 0;
	} 
	dfs(x, y);
	cout << tot << '\n';
	return 0;
}
