/*
    TASK:0/1 Knapsack
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[110][10010];
int main()
{
    int n,m,v,w;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&v,&w);
        for(int j=1;j<=m;j++){
            if(j<w) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w]+v);
        }
    }
    printf("%lld\n",dp[n][m]);
    return 0;
}