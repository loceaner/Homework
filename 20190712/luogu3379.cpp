#include <bits/stdc++.h>
#define N 500011
using namespace std;

struct node {
	int to, ne;
}e[N << 1];

int n, m, s, cnt, head[N], d[N], siz[N], son[N], top[N], f[N];

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

void add(int x, int y) {
	e[++cnt].to = y;
	e[cnt].ne = head[x];
	head[x] = cnt; 
}

void dfs1(int now) {
	siz[now] = 1;
	d[now] = d[f[now]] + 1;
	for(int i = head[now]; i; i = e[i].ne) {
		int dd = e[i].to;
		if(dd == f[now]) continue;
		f[dd] = now;
		dfs1(dd);
		siz[now] += siz[dd];
		if(!son[now] || siz[son[now]] < siz[dd]) son[now] = dd;
	}
}

void dfs2(int now, int tv) {
	top[now] = tv;
	if(son[now]) dfs2(son[now], tv);
	for(int i = head[now]; i; i = e[i].ne) {
		int dd = e[i].to;
		if(dd == f[now] || dd == son[now]) continue;
		dfs2(dd, dd);
	}
}

int main() {
	n = read(), m = read(), s = read();
	for(int i = 1; i < n; i++) {
		int x = read(), y = read();
		add(x, y);
		add(y, x);
	}
	dfs1(s);
	dfs2(s, s);
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read();
		while(top[x] != top[y]) {
			if(d[top[x]] >= d[top[y]]) x = f[top[x]];
			else y = f[top[y]];
		}
		cout << (d[x] < d[y] ? x : y) << '\n';
	}
	return 0;
}
/*
树剖就是把树剖分成若干条不相交的链，目前常用做法是剖成轻重链

所以我们定义siz[x]为以x为根结点的子树的结点个数

对于每个结点x，在它的所有子结点中寻找一个结点y

使得对于y的兄弟节点z，都有siz[y]≥siz[z]

此时x就有一条重边连向y，有若干条轻边连向他的其他子结点【比如z】

这样的话，树上的不在重链上的边的数量就会大大减少

然后我们每次求LCA（x,y）的时候就可以判断两点是否在同一链上

如果两点在同一条链上我们只要找到这两点中深度较小的点输出就行了

如果两点不在同一条链上

那就找到深度较大的点令它等于它所在的重链链端的父节点即为x=f[top[x]]

直到两点到达同一条链上，输出两点中深度较小的点
*/
