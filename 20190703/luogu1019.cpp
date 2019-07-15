#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

string a[21], sum, c;
int n, use[21], maxn = 0;

void dfs(string last) {
	if(last.size() == 1) sum = last;
	bool ans = 0;
	for(int i = 0; i < n; i++) {
		if(use[i] < 2) {
			int m;
			for(int j = last.size() - 1; j >= 0; j--) {
				if(last[j] == a[i][0]) {
					m = 1;
					ans = 1;
					while(last[j + m] == a[i][m]) m++;
				}
				if(ans && j + m == last.size()) break;
				if(ans && j + m != last.size()) ans = 0;
			}
			if(ans) {
				int len = sum.size();
				sum += a[i].substr(m, a[i].size() - m);
				use[i]++;
				dfs(a[i]);
				ans = 0;
				use[i]--;
				sum.erase(len, a[i].size() - m);
			}
		}
	}
	if(!ans && sum.size() > maxn)
		maxn = sum.size();
	return;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> c;
	dfs(c);
	cout << maxn << '\n';
	return 0;
}
