#include <bits/stdc++.h>
#define N 311
using namespace std;

const int dis[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int lu[400010][4], n, m, vis[N][N], sx, sy, dx, dy, a[N][N];
int ans = 0;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

struct node {
	int x, y;
	bool s;
} w1[27], w2[27];

void bfs() {
	int h = 0, t = 1;
	lu[t][1] = sx, lu[t][2] = sy, lu[t][3] = 1;
	a[sx][sy] = 1;
	while(h < t) {
		h++;
		for(int i = 0; i < 4; i++) {
			int x = lu[h][1] + dis[i][0], y = lu[h][2] + dis[i][1];
			for(int j = 1; j <= 26; j++) {
				if(x == w1[j].x && y == w1[j].y) {
					x = w2[j].x, y = w2[j].y;
					break;
				} else if(x == w2[j].x && y == w2[j].y) {
					x = w1[j].x, y = w1[j].y;
					break;
				}
			}
			if(x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == 0) {
				t++;
				a[x][y] = 1;
				lu[t][1] = x, lu[t][2] = y, lu[t][3] = lu[h][3] + 1;
				if(x == dx && y == dy) {
					ans = lu[t][3];
					h = t;
					break;
				}
			}
		}
	}
}

int main() {
	n = read(), m = read();
	char c;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> c;
			if(c == '.') a[i][j] = 0;
			else if(c == '#') a[i][j] = 1;
			else if(c == '=') a[i][j] = 0, dx = i, dy = j;
			else if(c == '@') a[i][j] = 0, sx = i, sy = j;
			else if(c >='A' && c <= 'Z') {
				a[i][j] = 0;
				if(w1[c - 'A' + 1].s == 0) w1[c - 'A' + 1].s = 1, w1[c - 'A' + 1].x = i, w1[c - 'A' + 1].y = j;
				else w2[c - 'A' + 1].s = 1, w2[c - 'A' + 1].x = i, w2[c - 'A' + 1].y = j;
			}
		}
	}
	bfs();
	cout << ans - 1 << '\n';
	return 0;
}
