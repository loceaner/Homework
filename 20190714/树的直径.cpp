#include <iostream>
#include <cstdio>
#include <cstring>
#define N 10011
using namespace std;

int head[N], n, cnt;

struct node {
	int to, nexii, cost;
} e[N << 1];

void add(int u, int v, int c) {
	e[++cnt].to = v;
	e[cnt].cost = c;
	e[cnt].nexii = head[u];
	head[u] = cnt;
	e[++cnt].to = u;
	e[cnt].cost = c;
	e[cnt].nexii = head[v];
	head[v] = cnt;
}

int dfs(int u, int f, int &ans) {
	int maxdep = 0;
	for(int p = head[u]; ~p; p = e[p].nexii) {
		int &v = e[p].to;
		if(v == f) continue;
		int tmp = dfs(v, u, ans) + e[p].cost;
		ans = max(ans, maxdep + tmp);
		maxdep = max(tmp, maxdep);
	}
	return maxdep;
}

int main() {
	memset(head, -1, sizeof(head));
	n = 1;
	int u, v, c;
	while(scanf("%d%d%d", &u, &v, &c) != EOF) {
		add(u, v, c);
		n++;
	}
	int ans = 0;
	dfs(1, 0, ans);
	cout << ans << '\n';
	return 0;
}
