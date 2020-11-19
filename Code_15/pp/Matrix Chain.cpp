//MatrixChain
#include<bits/stdc++.h>
using namespace std;
int mic[15][15],pa[15][15];
int a[15],b[15];
int dp(int st,int en)
{
    if(st==en)
        return 0;
    if(mic[st][en])
        return mic[st][en];
    int mi=INT_MAX;
    for(int i=st;i<en;i++)
    {
        if(mi>dp(st,i)+dp(i+1,en)+a[st]*b[i]*b[en])
            mi=dp(st,i)+dp(i+1,en)+a[st]*b[i]*b[en],pa[st][en]=i;
    }
    return mic[st][en]=mi;
}
void print(int st,int en)
{
    if(st==en)
    {
        printf("A%d",st);
        return ;
    }
    printf("(");
    print(st,pa[st][en]);
    printf(" x ");
    print(pa[st][en]+1,en);
    printf(")");
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d %d",&a[i],&b[i]);

    printf("%d\n",dp(1,n));
    print(1,n);
    return 0;
}
