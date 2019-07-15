#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#define ll long long
#define N 1000111
using namespace std;

int n;
char str[N << 1], s[111];
int ch[N][26], fail[N], val[N], last[N], q[N], l , r, Index;

void insert(char *s) {
	int len = strlen(s), u = 0;
	for(int i = 0; i < len; i++) {
		int c = s[i] - 'a';
		if(!ch[u][c]) ch[u][c] = ++Index;
		u = ch[u][c];
	}
	val[u]++;
}

void build() {
	l = 1, r = 0;
	fail[0] = 0;
	for(int c = 0; c < 26; c++) {
		int u = ch[0][c];
		if(u) fail[u] = 0, q[++r] = u, last[u] = 0;
	}
	while(l <= r) {
		int u = q[l++];
		for(int c = 0; c < 26; c++){
			int v = ch[u][c];
			if(!v) ch[u][c] = ch[fail[u]][c];
			else {
				q[++r] = v;
				fail[v] = ch[fail[u]][c];
				last[v] = val[fail[v]] ? fail[v] : last[fail[v]];
			}
		}
	}
}

int find(char *s) {
	int ans = 0, u = 0, len = strlen(s);
	for(int i = 0; i < len; i++) {
		int c = s[i] - 'a';
		u = ch[u][c];
		if(val[u]) ans += val[u], val[u] = 0;
		int p = u;
		while(last[p]) {
			p = last[p];
			if(val[p]) ans += val[p], val[p] = 0;
		}
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		cin >> s;
		insert(s);
	}
	build();
	scanf("%s", str);
	cout << find(str) << '\n';
	return 0;
}
