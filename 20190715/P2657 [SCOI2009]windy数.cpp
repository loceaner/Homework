#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int A, b;
int dp[12][10], a[12];

int dfs(int dep, int pre, int lead, int limit) {
	if(~dp[dep][pre] && !lead && (!limit || !dep)) return dp[dep][pre];
	if(dep == 0) return 0;
	int res = limit ? a[dep] : 9, ret = 0;
	for(int i = 0; i <= res; i++) {
		if(!lead && abs(pre - i) < 2) continue;
		if(!i && lead) ret += dfs(dep - 1, i, lead, limit&i == res);
		if(i && lead) ret += dfs(dep - 1, i, !lead, limit&i == res);
		if(!lead) ret += dfs(dep - 1, i, lead, limit&i == res);
	}
	if(!limit && !lead) dp[dep][pre] = ret;
	return ret;
}

int solve(int n) {
	if(!n) return 0;
	int cnt = 0;
	for(int i = 1; n; i++) a[++cnt] = n % 10, n /= 10;
	return dfs(cnt, 0, 1, 1);
}

int ocean(){
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i <= 9; i++) dp[0][i] = 1;
	scanf("%d%d", &A, &b);
	cout << solve(b) - solve(A - 1) << '\n';
	return 0;
}

int Loceaner = ocean();
int main(){;}
