#include<stdio.h>
#include<iostream>
using namespace std;
const char Stick[6][8]=
{
    "..+---+",
    "./   /|",
    "+---+ |",
    "|   | +",
    "|   |/.",
    "+---+.."
};//�������� 
int a[55][55];
char Paint[550][550];//���� 
inline void Draw(int x,int y)//Ϳѻ���� 
{
    int i,j;
    for(i=0;i<6;i++)
        for(j=0;j<7;j++)
            if(Stick[6-i-1][j]!='.')
                Paint[x-i][y+j]=Stick[6-i-1][j];//���÷��� 
}
int main()
{
	freopen("gensokyo.in", "r", stdin);
	freopen("gensokyo.out", "w", stdout);
    int N,M,K(0),L,i,j,x,y;
    scanf("%d%d",&N,&M);
    L=4*M+2*N+1;//���㻭����� 
    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
        {
            scanf("%d",&a[i][j]);
            K=max(K,a[i][j]*3+2*(N-i+1)+1);//���㻭������ 
        }
    for(i=1;i<=K;i++)
        for(j=1;j<=L;j++)
            Paint[i][j]='.';//������ʼ�� 
    for(i=1;i<=N;i++)    
        for(j=1;j<=M;j++)
        {
            x=K-2*(N-i);
            y=2*(N-i)+4*(j-1)+1;//�������� 
            while(a[i][j]--)
            {
                Draw(x,y);//Ϳѻ 
                x-=3;//���Ϸ� 
            }
        }
    for(i=1;i<=K;i++)
    {
        for(j=1;j<=L;j++)
            printf("%c",Paint[i][j]);
        printf("\n");
    }//��ӡ���� 
    return 0;
}
