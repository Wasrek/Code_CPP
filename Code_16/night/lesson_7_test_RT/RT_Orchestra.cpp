/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long qs[1000010],dp[110][510],cnt[110];
int main()
{
    int n,m,now,k,idx;
    long long all=0,ma,g,ans;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&now);
        cnt[now]++;
        qs[i]=qs[i-1]+i;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=1e18;
            for(int l=0;l<=j;l++){
                g=cnt[i]/(l+1);
                ans=qs[g]*(l+1);
                ans+=((cnt[i]%(l+1))*(g+1));
                dp[i][j]=min(dp[i][j],dp[i-1][j-l]+ans);
                // printf("%lld\n",ans);
                // printf("%lld ",dp[i][j]);
            }
        }
        // printf("\n");
    }
    printf("%lld\n",dp[m][k]);
    return 0;
}