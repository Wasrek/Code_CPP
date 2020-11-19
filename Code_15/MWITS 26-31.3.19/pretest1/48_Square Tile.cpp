/*
    TASK:48_Square Tile
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[370][370];
int main(){
    int q,n,m,i,j,k;
    for(i=1;i<=350;i++){
        for(j=1;j<=350;j++){
            if(i == j){
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = 1e9;
            for(k=1;k<=i-1;k++){
                dp[i][j]=min(dp[i][j],dp[i-k][j]+dp[k][j]);
            }
            for(k=1;k<=j-1;k++){
                dp[i][j]=min(dp[i][j],dp[i][j-k]+dp[i][k]);
            }
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        printf("%d\n",dp[n][m]);
    }
}
