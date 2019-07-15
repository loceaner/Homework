/*
加了单调队列优化的琪露诺qwq
100pts 
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

const int N = 500011;
int n, l, r, a[N], f[N];
int q[N<<1], head = 1, tail, ans;

int ocean() {
	n = read(), l = read(), r = read();
	for(int i = 0; i <= n; i++) a[i] = read();
	q[++tail] = 0;
	for(int i = l; i <= n + r; ++i) {
		while(head <= tail && f[i - l] > f[q[tail]]) tail--;
		q[++tail] = i - l;
		while(head <= tail && q[head] < i - r) head++;
		f[i] = f[q[head]] + a[i];
	}
	for(int i = l; i <= n + r; ++i) ans = max(ans, f[i]);
	cout << ans << '\n';
	return 0;
} 

int Loceaner = ocean();
int main(){;}
