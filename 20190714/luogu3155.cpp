#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define N 100011
using namespace std;

struct node {
	int v, next;
} edge[N << 1];

int head[N], tot = 0;
int f[N][2], c[N];
int n, m;

inline int read() {
	char c=getchar();
	int x=0,f=1;
	for(; !isdigit(c); c=getchar()) if(c=='-') f=-1;
	for(; isdigit(c); c=getchar()) x=x*10+c-48;
	return x*f;
}

inline void add(int u,int v) {
	edge[++tot]=(node) {
		v,head[u]
	};
	head[u]=tot;
}

inline void dfs(int u,int fa) {
	if(u<=n) {
		f[u][c[u]]=1;
		f[u][c[u]^1]=INF;
		return;
	}
	f[u][0]=f[u][1]=1;
	for(int i=head[u]; i; i=edge[i].next) {
		int v=edge[i].v;
		if(v==fa)continue;
		dfs(v,u);
		f[u][0]+=min(f[v][1],f[v][0]-1);
		f[u][1]+=min(f[v][0],f[v][1]-1);
	}
}

int main() {
	m=read();
	n=read();
	for(int i=1; i<=n; i++)c[i]=read();
	for(int i=1; i<m; i++) {
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs(n+1,0);
	printf("%d",min(f[n+1][0],f[n+1][1]));
	return 0;
}
