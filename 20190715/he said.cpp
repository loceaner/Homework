#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;

int main() {
	int n,i,ans=0;
	scanf("%d",&n);
	for(i=1; i<=n; i++)
		ans+=n/i;
	printf("%d\n",ans);
}
