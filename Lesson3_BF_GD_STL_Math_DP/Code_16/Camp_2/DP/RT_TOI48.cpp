/*
    TASK:RT_TOI48
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int v[5010],t[5050],dp[5010][15010];
int main()
{
    int n,k,w;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&w);
        w++;
        w*=8;
        for(int j=1;j<=k;j++){
            if(j<w) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w]+v[i]);
        }
    }
    printf("%d\n",dp[n][k]);
    return 0;
}