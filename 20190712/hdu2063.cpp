#include<stdio.h>  
#include<string.h>  
using namespace std;  
const int maxn = 505;  
  
int map[maxn][maxn];              //记录是否可以匹配，0表示不能，1表示能  
int vis[maxn];                  //用在不同队伍匹配是的标记作用  
int pri[maxn];  
int k,m,n;  
int  find(int x)  
{  
    for(int i=1;i<=m;i++)  
    {  
        if(vis[i]==0&&map[i][x])  
        {  
            vis[i]=1;  
            if(pri[i]==-1||find(pri[i]))  
            {  
                pri[i]=x;  
                return 1;  
            }  
        }  
    }  
    return 0;  
}  
int main()  
{  
    while(~scanf("%d",&k))  
    {  
        if(k==0)break;  
        scanf ("%d%d", &m, &n);  
        memset (map, 0, sizeof (map));  
        memset (pri, -1, sizeof (pri));  
        for(int i=0;i<k;i++)  
        {  
            int a,b;  
            scanf("%d%d",&a,&b);  
            map[a][b]=1;  
        }  
        int output=0;  
        for(int i=1;i<=n;i++)  
        {  
            memset(vis,0,sizeof(vis));  
            if(find(i))  
            output++;  
        }  
        printf("%d\n",output);  
    }  
    