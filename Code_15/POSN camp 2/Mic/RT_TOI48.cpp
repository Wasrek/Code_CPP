/*
    TASK:RT_TOI48
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[5010][15010],a[5010],n,k,w,i,j;
int main(){
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&w);
        w++;w*=8;
        for(j=1;j<=k;j++){
            if(j<w) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w]+a[i]);
        }
    }
    printf("%d\n",dp[n][k]);
    return 0;
}
