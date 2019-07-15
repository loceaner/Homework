#include<bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 5;
int a[maxn];
int b[maxn];
int c[maxn];
int n;
struct l {
	int to , next , val;
} line[maxn];
int cnt;
int first[maxn];
void insert(int u , int v , int val) {
	cnt ++;
	line[cnt].next = first[u];
	line[cnt].to = v;
	line[cnt].val = val;
	first[u] = cnt;
}
int fa[maxn];
void dfs(int now) {
	for(int i = first[now] ; i ; i = line[i].next) {
		int v = line[i].to;
		if(fa[now] == v) continue;
		fa[v] = now;
		dfs(v);
		int x = a[v] + line[i].val;
		if(x > a[now]) {
			b[now] = a[now];
			a[now] = x;
		} else if(x > b[now]) {
			b[now] = x;
		}
	}
}
int q[maxn];
void dfs2(int now) {
	int mx = c[now];
	int tp = 0;
	for(int i = first[now] ; i ; i = line[i].next) {
		int v = line[i].to;
		if(fa[v] != now) continue;
		q[++tp] = i;
	}
	for(int i = 1 ; i <= tp ; i ++) {
		int v = line[q[i]].to;
		c[v] = max(c[v] , mx + line[q[i]].val);
		mx = max(mx , a[v] + line[q[i]].val);
	}
	mx = c[now];
	for(int i = tp ; i >= 1 ; i --) {
		int v = line[q[i]].to;
		c[v] = max(c[v] , mx + line[q[i]].val);
		mx = max(mx , a[v] + line[q[i]].val);
	}
	for(int i = first[now] ; i ; i = line[i].next) {
		int v = line[i].to;
		if(fa[now] == v) continue;
		dfs2(v);
	}
}
int main() {
	freopen("kikaku.in","r",stdin);
	freopen("kikaku.out","w",stdout);
	cin >> n;
	for(int i = 1 ; i < n ; i ++) {
		int u , v , val;
		scanf("%d%d%d",&u,&v,&val);
		insert(u , v , val);
		insert(v , u , val);
	}
	dfs(1);
	dfs2(1);
	for(int i = 1 ; i <= n ; i ++) {
		printf("%d ",max(a[i] + b[i] , a[i] + c[i]));
	}
}
