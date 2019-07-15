#include <bits/stdc++.h>
using namespace std;

const int N = 1000111; 
int n, a[N], h[N], cnt, last, ch[N][26], sz[N], fail[N];
char s[N];


void ins(int x) {
	cin >> (s + 1);
	int now = 0, len = strlen(s + 1);
	for(int i = 1; i <= len; i++) {
		int u = s[i] - 'a';
		if(!ch[now][u]) ch[now][u] = ++cnt;
		now = ch[now][u];
		sz[now]++;
	}
	a[x] = now;
}

void build() {
	int he = 0, t = 0;
	for(int i = 0; i < 26; i++) if(ch[0][i]) h[++t] = ch[0][i];
	while(he < t) {
		int x = h[++he], y;
		for(int i = 0; i < 26; i++) {
			if(y = ch[x][i]) {
				h[++t] = y;
				fail[y] = ch[fail[x]][i];
			}
			else ch[x][i] = ch[fail[x]][i];
		}
	}
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) ins(i);
	build();
	for(int i = cnt; i >= 0; i--) sz[fail[h[i]]] += sz[h[i]];
	for(int i = 1; i <= n; i++) cout << sz[a[i]] << '\n';
	return 0;
}