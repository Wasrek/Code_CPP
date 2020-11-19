/*
    TASK:PT_Choco
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[510][510];
int main(){
    int i,j,k,l,q,c,v;
    scanf("%d",&q);
    memset(dp,-1,sizeof dp);
    dp[0][0]=0;
    for(i=0;i<=33;i++){
        for(j=0;j<=33;j++){
            if(i==0 && j==0) continue;
            for(k=500-i;k>=0;k--){
                for(l=500-j;l>=0;l--){
                    if(dp[k][l]>=0){
                        dp[k+i][l+j]=max(dp[k+i][l+j],dp[k][l]+1);
                    }
                }
            }
        }
    }
    while(q--){
        scanf("%d %d",&c,&v);
        printf("%d\n",dp[c][v]);
    }
}
