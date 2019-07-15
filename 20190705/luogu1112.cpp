#include <bits/stdc++.h>
#define N 10000000
using namespace std;

int l1, l2, r1, r2, num, maxn, minn;
int cnt[N];

int build(int a, int b, int k, int len) {
	int x = 0;
	for(int i = 1; i <= len; i++) {
		if(i & 1) x = x * k + a;
		else x = x * k + b;
	}
	return x;
}

int calc(int x, int k) {
	int cnt = 0;
	while(x) {
		x = x / k;
		cnt++;
	}
	return cnt;
}

int main() {
	scanf("%d%d%d%d%d", &l1, &r1, &l2, &r2, &num);
	for(int k = l1; k <= r1; k++) {
		for(int i = 1; i < k; i++) {
			for(int j = 0; j < k; j++) {
				if(i!=j) {
					minn = calc(l2, k);
					maxn = calc(r2, k);
					for(int l = minn; l <= maxn; l++) {
						int tmp = build(i, j, k, l);
						if(tmp >= l2 && tmp <= r2) {
							cnt[tmp]++;
						}
					}
				}
			}
		}
	}
	for(int i = l2; i <= r2; i++) {
		if(cnt[i] == num) {
			cout << i << '\n';
		}
	}
	return 0;
}

