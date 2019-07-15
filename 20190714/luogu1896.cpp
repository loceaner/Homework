/*

诡异的状态压缩DP,弱弱地说一句：我不会，只会抄！ 

*/
#include <bits/stdc++.h>
#define MAXN 12
using namespace std;

typedef long long ll;
ll f[MAXN][(1 << 15) + 2][MAXN * 3];
int c[(1 << 15) | 1], v[(1 << 15) | 1], N, C;

void dfs(int n, int s, int p) {
	if(p > N) {
		v[++C] = n, C[c] = s;
		return;
	}
	dfs(n + (1 << (p - 1)), s + 1, p + 2);
	dfs(n, s, p + 1);
}

int main() {
	int K;
	scanf("%d%d", &N, &K);
	dfs(0, 0, 1);
	for(int i = 1; i <= C; i++) f[1][v[i]][c[i]] = 1LL;
	for(int i = 2; i <= N; i++) {
		for(int j = 1; j <= C; j++) {
			for(int k = 1; k <= C; k++) {
				if(v[j] & v[k]) continue;
				if(((v[j] << 1) & v[k]) || ((v[j] >> 1) & v[k])) continue;
				for(int l = K; l >= c[j]; l--) f[i][v[j]][l] += f[i - 1][v[k]][l - c[j]];
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i <= C; i++) ans += f[N][v[i]][K];
	cout << ans << '\n';
	return 0;
}
