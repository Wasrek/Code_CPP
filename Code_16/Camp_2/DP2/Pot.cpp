/*
    TASK:Pot
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100],qs[100100];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    k=min(k,n);
    dp[0]=1;
    qs[0]=1;
    qs[1]=2;
    for(int i=2;i<=n;i++){
        if(i-k-1>=0)
        dp[i]=qs[i-1]-qs[i-k-1];
        else dp[i]=qs[i-1];
        qs[i]=dp[i]+qs[i-1];
        dp[i]+=2009;
        dp[i]%=2009;
        qs[i]+=2009;
        qs[i]%=2009;
    }
    // for(int i=1;i<=n;i++) printf("%d ",dp[i]);
    printf("%d\n",dp[n]);
    return 0;
}