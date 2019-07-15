#include <bits/stdc++.h>
#define int long long
#define N 10000011
#define mod 1000000007
using namespace std;

int jc1[N], jc2[N], n, m, inv[N], c[N];

long long C(long long n,long long m){
	return ((jc1[n]*jc2[m])%mod*jc2[n-m])%mod;
}

long long lucas(long long n,long long m){
	return (C(n%mod,m%mod)*C(n/mod,m/mod))%mod; 
}

int lucas(int n,int m){
	if(n<mod&&m<mod) return c[n][m];
	return lucas(n%mod,m%mod)*lucas(n/mod,m/mod)%mod;
}

void work(){
	inv[0]=inv[1]=1;
	for(int i=2;i<N;i++) inv[i]=((mod-mod/i)*inv[mod%i])%mod;
	jc1[0]=1;
	for(int i=1;i<N;i++) jc1[i]=jc1[i-1]*i%mod;
	jc2[0]=1;
	for(int i=1;i<N;i++) jc2[i]=jc2[i-1]*inv[i]%mod;
}
	


signed main() {

	return 0;
}