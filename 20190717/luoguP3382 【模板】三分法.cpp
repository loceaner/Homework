#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int n;
const double eps = 1e-6;
double l, r, a[20], mid, mmid, k; 

double f(double x) {
	double s = 0;
	for(int i = 0; i <= n; i++) s = s * x + a[i];
	return s;
}

int main() {
	scanf("%d%lf%lf", &n, &l, &r);
	for(int i = 0; i <= n; i++) scanf("%lf", &a[i]);
	while(r - l >= eps) {
		k = (r - l) / 3.0;
		mid = l + k;
		mmid = r - k;
		if(f(mid) > f(mmid)) r = mmid;
		else l = mid;
	}
	printf("%.5lf\n", l);
	return 0;
}
