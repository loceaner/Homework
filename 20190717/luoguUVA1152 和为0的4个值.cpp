#include<bits/stdc++.h>
#define N 4005
#define LL long long
using namespace std;

int T,n,A[N],B[N],C[N],D[N],sum[N*N];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
		}
		int c = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j< n; j++) {
				sum[c++] = A[i] + B[j];
			}
		}
		stable_sort(sum, sum + c);
		LL ans=0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				ans += upper_bound(sum, sum + c,-C[i]-D[j]) - lower_bound(sum, sum + c, -C[i]-D[j]);
			}
		}
		printf("%lld\n", ans);
		if(T) printf("\n");
	}
	return 0;
}
