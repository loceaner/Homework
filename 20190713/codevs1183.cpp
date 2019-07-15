#include<bits/stdc++.h>
#define N 111
using namespace std;

int p[N][N], t[N][N];
double f[N][N], dis[N * N];
bool vis[N * N];
int q[N * N], tim[N * N];
int n, head, tail;

int spfa(int s) {
	memset(dis, -0x3f, sizeof(dis));
	memset(vis, false, sizeof(vis));
	memset(tim, 0, sizeof(tim));
	memset(q, 0, sizeof(q));
	head = 0, tail = 0;
	dis[s] = 0;
	vis[s] = true;
	q[++tail] = s;
	tim[s]++;
	while(head != tail) {
		int now = q[++head];
		for(int i = 1; i <= n; i++) {
			if(p[now][i] != 0 && dis[i] < dis[now] + f[now][i]) {
				dis[i] = dis[now] + f[now][i];
				if(!vis[i]) {
					tim[i]++;
					q[++tail] = i;
					vis[i] = true;
					if(tim[i] > n) return true;
				}
			}
		}
		vis[now] = false;
	}
	if(dis[n] > 0) return true;
	return false;
} 

int check(double x) {
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			f[i][j] = p[i][j] - x * t[i][j];
		}
	}
	if(spfa(1)) return 1;
	return 0;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int  j = 1; j <= n; j++) {
			scanf("%d", &p[i][j]);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &t[i][j]);
		}
	}
	double eps = 1e-4;
	double l = 0, r = 1000001;
	while(r - l > eps) {
		double mid = (l + r) / 2;
		if(check(mid)) l = mid;
		else r = mid;
	}
	printf("%.3lf", l);
}
