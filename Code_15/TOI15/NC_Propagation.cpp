/*
    TASK:NC_Propagation
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 10007
struct A
{
    int a[210][210];
};
int n;
A m[35],ans;
A mul(A a,A b)
{
    A tmp;
    int i,j,k;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            tmp.a[i][j]=0;
            for(k=1; k<=n; k++)
            {
                tmp.a[i][j]+=((a.a[i][k]*b.a[k][j])%mod);
                tmp.a[i][j]%=mod;
            }
        }
    }
    return tmp;
}
int main()
{
    int h,t,i,u,v,j;
    scanf("%d %d %d",&n,&h,&t);
    while(h--)
    {
        scanf("%d %d",&u,&v);
        m[0].a[u][v]=1;
        m[0].a[v][u]=1;
    }
    for(i=1; i<=n; i++)
    {
        m[0].a[i][i]=1;
        for(j=1; j<=n; j++)
        {
            ans.a[i][j]=0;
        }
        ans.a[i][i]=1;
    }
    ans.a[1][1]=1;
    for(i=1; i<=30; i++)
    {
        m[i]=mul(m[i-1],m[i-1]);
    }
    for(i=0; i<=30; i++)
    {
        if((1<<i) & t)
        {
            ans=mul(ans,m[i]);
        }
    }
    for(i=1; i<=n; i++)
    {
        printf("%d ",ans.a[1][i]);
    }
    printf("\n");
    return 0;
}
