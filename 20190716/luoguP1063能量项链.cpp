#include<iostream>
#include<cstdio>
using namespace std;
int n,t[300],s[300][300],maxn;
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&t[i]);
		t[i+n]=t[i];
	}
	for(int i=2; i<n*2; i++) {
		for(int j=i-1; i-j<n&&j>=1; j--) {
			for(int k=j; k<i; k++)
				s[j][i]=max(s[j][i],s[j][k]+s[k+1][i]+t[j]*t[k+1]*t[i+1]);
			if(s[j][i]>maxn)maxn=s[j][i];
		}
	}
	printf("%d",maxn);
	return 0;
}
