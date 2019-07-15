#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn=1000010;
int m=1000000;
ll n,p;
ll jc[maxn],jcc[maxn],ine[maxn],f[maxn];
int Log[maxn];
ll C(ll a,ll b)
{
    if(a<b)  return 0;
    if(!b)  return 1;
    if(a<p&&b<p)  return jc[a]*jcc[b]%p*jcc[a-b]%p;
    return C(a%p,b%p)*C(a/p,b/p)%p;
}
ll calc(ll x)
{
    if(f[x])    return f[x];
    ll a=x-(1<<Log[x+1])+1;
    if(a<(1<<Log[x+1]-1))  a=(1<<Log[x+1]-1)-1+a;
    else    a=(1<<Log[x+1])-1;
    return f[x]=C(x-1,a)*calc(a)%p*calc(x-a-1)%p;
}
int main()
{
    scanf("%lld%lld",&n,&p);
    if(m>=p) m=p-1;
    ll i;
    jc[0]=jcc[0]=1,ine[0]=ine[1]=1;
    for(i=2;i<=m;i++)    ine[i]=(p-(p/i)*ine[p%i]%p)%p;
    for(i=1;i<=m;i++)    jc[i]=jc[i-1]*i%p,jcc[i]=jcc[i-1]*ine[i]%p;
    for(i=2;i<=n+1;i++)  Log[i]=Log[i>>1]+1;
    f[0]=f[1]=1;
    printf("%lld",calc(n));
    return 0;
    }