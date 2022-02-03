/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[3][3][110];
int main()
{
    int n,k,q,a,b,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        for(int i=0;i<=k+1;i++)
            for(int j=0;j<=1;j++)
                dp[0][j][i]=dp[1][j][i]=2e9;
        dp[0][0][0]=dp[1][0][0]=0;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a,&b);
            for(int j=0;j<=k;j++){
                dp[0][i%2][j]=dp[1][i%2][j]=2e9;
                if(j>0){
                    dp[0][i%2][j]=min(dp[0][i%2][j],dp[0][(i-1)%2][j-1]+a);
                    dp[1][i%2][j]=min(dp[1][i%2][j],dp[1][(i-1)%2][j-1]+b);
                }
                if(j<k){
                    dp[0][i%2][j]=min(dp[0][i%2][j],dp[0][(i-1)%2][j+1]+b);
                    dp[1][i%2][j]=min(dp[1][i%2][j],dp[1][(i-1)%2][j+1]+a);
                }
                // printf("%lld %lld %lld\n",dp[0][i%2][j],dp[1][i%2][j],j);
            }
            dp[1][i%2][0]=min(dp[0][i%2][0],dp[1][i%2][0]);
            dp[0][i%2][0]=dp[1][i%2][0];
        }
        ans=2e9;
        for(int i=0;i<=1;i++){
            for(int j=0;j<=k;j++){
                ans=min(ans,dp[i][n%2][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
