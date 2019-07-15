#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#define N 1000011
using namespace std;

string s, p;
int cnt;
int next[N], lens, lenp;
int ans[N], n, m;

void kmp() {
	int i = 0, j = 0;
	while(i < lens) {
		if(j == -1 || s[i] == p[j]) {
			i++;
			j++;
		} else j = next[j];
		if(j == lenp) ans[cnt++] = i - lenp + 1;
	}
}

void getnext() {
	int i = 0, j = -1;
	next[0] = -1;
	while(i < lenp) {
		if(j == -1 || p[j] == p[i]) {
			i++;
			j++;
			next[i] = j;
		} else j = next[j];
	}
}

int main() {
	cin >> s >> p;
	lens = s.size();
	lenp = p.size();
	getnext();
	kmp();
	for(int i = 0; i < cnt; i++) cout << ans[i] << '\n';
	for(int i = 1; i <= lenp; i++) cout << next[i] << ' ';
	return 0;
}
