#include <bits/stdc++.h>
#define N 1011
using namespace std;

bool g[N][N], vis[N];
int minn = N, maxn;
int n, a[N], inde[N], pos, cnt, camera[N];

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for(; !isdigit(c); c=getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c=getchar()) x = x * 10 + c - 48;
	return x * f;
}

int main() {
	n = read();
	for(int i = 1; i <= n; i++) {
		int x = read(), m = read(), y;
		vis[x] = true;
		camera[x] = true;
		minn = min(minn, x);
		maxn = max(maxn, x);
		while(m--) {
			y = read();
			g[x][y] = true;
			vis[y] = true;
			minn = min(minn, x);
			maxn = max(maxn, x);
			inde[y]++;
		}
	}
	queue<int> q;
	for(int i = minn; i <= maxn; i++) {
		if(vis[i]) {
			cnt++;
			if(inde[i] == 0) {
				q.push(i);
			}
		}
	}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		a[++pos] = u;
		for(int v = minn; v <= maxn; v++) {
			if(!g[u][v]) continue;
			inde[v]--;
			if(inde[v] == 0) q.push(v);
		}
	}
	int ans = n;
	for(int i = 1; i <= pos; i++) {
		if(camera[a[i]]) ans--;
	}
	if(ans) cout << ans;
	else cout << "YES";
	return 0;
}
