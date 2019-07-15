#include <bits/stdc++.h>
using namespace std;

const int N = 50 + 1;

int n, m, t, x, y, sx, sy, tx, ty, tot = 0;
int a[N][N], vis[N][N];
int f[5][3] = {{0, 0, 0},{0, 0, 1},{0, 0, -1},{0, 1, 0},{0, -1, 0}};

void dfs(int x, int y) {
	if(x == tx && y == ty) {
		tot++;
		return;
	}
	for(int i = 1; i <= 4; i++) {
		int nx = x + f[i][1];
		int ny = y + f[i][2];
		if(nx > 0 && ny > 0 && nx <= n && ny <= n && !a[nx][ny] && !vis[nx][ny]){
			vis[nx][ny] = true;
			dfs(nx, ny);
			vis[nx][ny] = false;
		}
	}
	
}

int main() {
	scanf("%d%d%d", &n, &m, &t);
	scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
	a[sx][sy] = true;
	while(t--) {
		scanf("%d%d", &x, &y);
		a[x][y] = true;
	}
	dfs(sx, sy);
	cout << tot << '\n';
	return 0;
}
