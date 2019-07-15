/*
设f[i]表示到达i点可获得的最大冰冻指数
则f[i]=max(f[j]+a[i],（i-r<=j<=i-l）
但由于数据范围很大，只能拿60分 
60pts
*/
#include <iostream>
#include <cstdio>
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

const int N = 200005;
int n, l, r, a[N], f[N], ans;

int Work() {
	n = read(), l = read(), r = read();
	for(int i = 0; i <= n; ++i) a[i] = read();
	for(int i = 0; i < l; ++i) f[i] = 0;
	for(int i = l; i <= n + r; ++i) {
		for(int j = max(0, i - r); j <= i - l; ++j)
			f[i] = max(f[i], f[j] + a[i]);
	}
	for(int i = n; i <= n + r; ++i) ans = max(ans, f[i]);
	cout << ans << '\n';
	return 0;
}

int Loceaner=Work();
int main() {;}
