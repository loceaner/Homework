/*
	一个简单的模拟，重点在于dfs时的边界条件以及递归三个模块的参数 
*/
#include <bits/stdc++.h>
#define N 1 << 10
using namespace std;

int a[N][N], n;

void solve(int x, int y, int l) {
	if(a[x][y]) return;
	for(int i = x; i <= x + l - 1; i++) {
		for(int j = y; j <= y + l - 1; j++) {
			a[i][j] = 1;
		}
	}
	if(l == 1) return;
	solve(x + l, y, l >> 1);
	solve(x, y + l, l >> 1);
	solve(x + l, y + l, l >> 1);
}

int main() {
	scanf("%d", &n);
	int p = 1 << n;
	solve(1, 1, p / 2);
	for(int i = 1; i <= p; i++) {
		for(int j = 1; j <= p; j++) {
			cout << 1 - a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
