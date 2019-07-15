#include <bits/stdc++.h>
#define N 1000011
using namespace std;

int n, m, e;
int match[N], head[N], cnt, ans;
bool used[N];

struct node {
	int next, to;
} edge[N];

void add(int bg, int ed) {
	edge[++cnt].to = ed;
	edge[cnt].next = head[bg];
	head[bg] = cnt;
}

inline int find(int x) {
	for(int i = head[x]; i; i = edge[i].next) {
		int u = edge[i].to;
		if(!used[u]) {
			used[u] = 1;
			if(!match[u] || find(match[u])) {
				match[u] = x;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	scanf("%d%d%d", &n, &m, &e);
	for(int i = 1; i <= e; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(b > m || a > n) continue;
		add(a, b);
	}
	for(int i = 1; i <= n; i++) {
		memset(used, false, sizeof(used));
		if(find(i)) ans++;
	}
	cout << ans << '\n';
	return 0;
}
