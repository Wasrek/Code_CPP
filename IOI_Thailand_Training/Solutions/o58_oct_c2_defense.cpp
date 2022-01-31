/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[3010][3010];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        long long val;
        scanf("%lld",&val);
        if(i<=k-1){
            dp[i][0]= val;
        }
        for(int j=max(1,i-k+1);j<=i-1;j++){
            dp[i][j]=dp[j][max(0,i-k)]+val;
        }
        for(int j=i-2;j>=max(0,i-k+1);j--){
            dp[i][j]=min(dp[i][j],dp[i][j+1]);
        }
    }
    long long ans=1e18;
    for(int i=n-k+2;i<=n;i++){
        ans=min(ans,dp[i][n-k+1]);
    }
    printf("%lld\n",ans);
}