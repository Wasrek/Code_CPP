/*
    TASK:0/1 Knapsack
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[110][10100];
int main(){
    int n,m,i,j,v,w;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d %d",&v,&w);
        for(j=1;j<=m;j++){
            if(j<w) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],v+dp[i-1][j-w]);
        }
    }
    printf("%d\n",dp[n][m]);
    return 0;
}
