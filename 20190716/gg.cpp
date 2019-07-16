#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define N 1000011
using namespace std;

int n, m, e;
int match[N], head[N], cnt, ans;
bool used[N];

struct node {
	int next, to;
} edge[N];

inline void add(int bg, int ed) {
	edge[++cnt].to = ed;
	edge[cnt].next = head[bg];
	head[bg] = cnt;
}

int find(int x) {
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

int ocean() {
	freopen("gg.in", "r", stdin);
	freopen("gg.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &e);
	for(int i = 1; i <= e; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		if(v > m || u > n) continue;
		add(u, v);
	}
	for(int i = 1; i <= n; i++) {
		memset(used, false, sizeof(used));
		if(find(i)) ans++;
	}
	cout << ans << '\n';
	return 0;
}

int loceaner = ocean();
int main() {;}
