#include <iostream>
#include <cstdio>
#define maxn 200010
using namespace std;

int n, a[maxn];
int main() {
	scanf("%d", &n);
	if(n % 4 > 1) {
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n / 4; i++) {
		a[2 * i - 1]=2 * i;
		a[2 * i] = n + 2 - 2 * i;
		a[n - 2 * i + 2] = n + 1 - 2 * i;
		a[n - 2 * i + 1 ] = 2 * i - 1;
	}
	if(n % 2 == 1) a[n / 2 + 1] = (n + 1) / 2;
	for(int i = 1; i <= n; i++) printf("%d ", a[i]);
}
