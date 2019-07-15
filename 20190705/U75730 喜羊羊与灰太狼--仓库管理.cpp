#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;

priority_queue<int,vector<int>,greater<int> > a;
int n;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

signed main() {
	n = read();
	char x;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		if(x == 'i'){
			int k = read();
			a.push(k);
		}
		if(x == 'q') {
			cout << a.top() << '\n';
			a.pop();
		}
	}
	return 0;
}
