#include <bits/stdc++.h>
using namespace std;

int ans, x, y, flag;
int n, i ,j;

int main() {
	scanf("%d%d%d", &n, &i, &j);
	if(i > n/2) y = n - i + 1;
	else y = i;
	if(j > n/2) x = n - j + 1;
	else x = j;
	int m = min(x, y);
	flag = 1;
	for(int k = 1; k <= m - 1; k++) {
		flag += 4 * (n - 1);
		n -= 2;
	}
	
	int x2 = i - m + 1, y2 = j - m + 1;
	if(x2 == 1) {
		cout << flag + y2 - 1;
		return 0;
	}
	if(y2 == 1) {
		cout << flag + 4 * (n - 1) -1 - x2 + 2;
		return 0;
	}
	if(y2 > x2) {
		cout << flag + n - 1 + x2 -1;
		return 0;
	}
	if(x2 > y2) {
		cout << flag + 4 * (n - 1) -1 - n + 2 - y2 + 1;
		return 0;
	}
	if(x2 == y2) {
		cout << flag + (n - 1) + (n - 2) + 1;
		return 0;
	}
	return 0;
}
