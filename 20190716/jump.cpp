#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctype.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define int long long
using namespace std;

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48); 
	return x * f;
}

const int mod = 19260817;
int n, m;
struct matrix {
	int map[55][55];
}f, map, ans;
int tmp[2][60];

matrix operator * (const matrix &a, const matrix &b) {
	matrix c;
	memset(c.map, 0, sizeof(c.map));
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				c.map[i][j] = (c.map[i][j] + a.map[i][k] * b.map[k][j] % mod) % mod;
			}
		}
	}
	return c;
}

inline void build(matrix &map) {
	for(int i = 1; i <= n; i++) map.map[i][i] = 1;
}

inline void quick_power(matrix &ans,int k)
{
	while(k)
	  {
	  	if(k&1) ans=ans*map;
	  	map=map*map;
	  	k>>=1;
	  }
}

signed main() {
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
	n = read(), m = read();
	int l = n / 2 + 1, r = n / 2 + 1, now = 1;
	tmp[!now][l] = 1;
	
	for(int i = 2; i <= n; i++) {
		for(int j = l - 1; j <= r + 1; j++) tmp[now][j] = 0;
		for(int j = l; j <= r; j++) {
			tmp[now][j - 1] = (tmp[now][j - 1] + tmp[!now][j]) % mod;
			tmp[now][j] = (tmp[now][j] + tmp[!now][j]) % mod;
			tmp[now][j + 1] = (tmp[now][j + 1] + tmp[!now][j]) % mod;
		}
		now = !now, l = max(l - 1, 1), r = min(r + 1, n); 
	}
	
	if(n >= m) {
		for(int i = 1; i <= n; i++) cout << tmp[!now][i] << ' '; 
		return 0;
	}
	
	for(int i = 1; i <= n; i++) f.map[1][i] = tmp[!now][i];
	for(int i = 1; i <= n; i++) {
		for(int j = i - 1; j <= i + 1; j++) {
			map.map[i][j] = 1;
		}
	}
	
	build(ans);
	quick_power(ans, m - n);
	f = f * ans;
	
	for(int i = 1; i <= n; i++) cout << f.map[1][i] << ' ';
	
	return 0;
}
