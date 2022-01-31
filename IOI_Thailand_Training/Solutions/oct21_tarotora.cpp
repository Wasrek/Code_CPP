/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100][210];
int main()
{
    int q,n,a,b;
    int ans;
    scanf("%d",&q);
    while(q--){
        int n,k;
        scanf("%d %d",&n,&k);
        for(int i=0;i<=k*2;i++){
            dp[0][i]=2e9;
        }
        dp[0][k]=0;
        ans=2e9;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a,&b);
            for(int j=0;j<=k*2;j++){
                dp[i][j]=2e9;
                if(j!=0) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+a);
                if(j!=k*2) dp[i][j]=min(dp[i][j],dp[i-1][j+1]+b);
                if(i==n)ans=min(ans,dp[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}