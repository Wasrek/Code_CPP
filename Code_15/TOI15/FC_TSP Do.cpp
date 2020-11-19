/*
    TASK:FC_TSP Do
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[1505][1505],qs[1505],dis[1505][1505];
int main()
{
    long long n,i,j,ans;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%lld",&dis[i][j]);
    memset(dp,127,sizeof(dp));
    dp[1][2]=dis[1][2];
    dp[1][1]=0;
    for(i=2;i<=n;i++)
        qs[i]=qs[i-1]+dis[i-1][i];
    for(i=2;i<=n;i++)
    {
        for(j=1;j<i;j++)
            dp[i][j]=min(dp[i][j],dp[i-1][j]+dis[i][i-1]);
        for(j=1;j<i-1;j++)
            dp[i][i-1]=min(dp[i][i-1],dis[i][j]+dp[j][j+1]+qs[i-1]-qs[j+1]);
        for(j=1;j<i;j++)
            dp[i][i+1]=min(dp[i][i+1],dp[i][j]+dis[j][i+1]);
    }
    ans=LONG_LONG_MAX;
    for(i=1;i<n;i++)
        ans=min(ans,dp[i][i+1]+qs[n]-qs[i+1]);
    for(i=1;i<n;i++)
        ans=min(ans,dp[n][i]);
    printf("%lld",ans);
    return 0;
}
