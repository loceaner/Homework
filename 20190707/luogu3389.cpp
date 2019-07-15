#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define N 105
using namespace std;

const double eps = 1e-8;
int n;
double a[N][N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n + 1; j++) {
			scanf("%lf", &a[i][j]);
		}
	}
	for(int i = 1; i <= n; i++) {
		int p = i;
		for(int j = i + 1; j <= n; j++) if(fabs(a[j][i]) > fabs(a[p][i])) p = j;
		for(int j = 1; j <= n + 1; j++) swap(a[p][j], a[i][j]);
		if(fabs(a[i][i]) < eps) continue;
		double tmp = a[i][i];
		for(int j = 1; j <= n + 1; j++) a[i][j] /= tmp;
		for(int j = 1; j <= n; j++) {
			if(i != j) {
				double tmp = a[j][i];
				for(int k = 1; k <= n + 1; k++) {
					a[j][k] -= a[i][k] * tmp;
				}
			}
		}
	}
	int ult = 0;
	for(int i = 1; i<= n; i++) {
		int j = 1;
		while(fabs(a[i][j]) < eps && j <= n + 1) j++;
		if(j > n + 1) ult = 1;
	}
	if(ult) {
		cout << "No Solution\n";
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		printf("%.2lf\n", a[i][n + 1]);
	}
	return 0;
}
