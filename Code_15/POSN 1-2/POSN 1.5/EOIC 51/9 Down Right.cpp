/*
    TASK:Down Right
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[260][260];
int main()
{
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&dp[i][j]);
            dp[i][j]+=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    printf("%d\n",dp[n][m]);
    return 0;
}
