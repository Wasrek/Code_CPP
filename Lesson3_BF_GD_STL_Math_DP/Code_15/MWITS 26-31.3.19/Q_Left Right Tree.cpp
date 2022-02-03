/*
    TASK:Q_Left Right Tree
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[150][150];
int main(){
    long long n,m,q,i,j,k,l;
    scanf("%lld",&q);
    dp[0][0]=1;
    for(i=0;i<=125;i++){
        for(j=0;j<=125;j++){
            if(i-1>=0)
            dp[i][j]+=dp[i-1][j],dp[i][j]%=9999991;
            if(j-1>=0)
            dp[i][j]+=dp[i][j-1],dp[i][j]%=9999991;
            for(k=0;k<i;k++){
                for(l=0;l<j;l++){
                    dp[i][j]+=(dp[k][l]*dp[i-k-1][j-l-1])%9999991;dp[i][j]%=9999991;
                }
            }
        }
    }
    while(q--){
        scanf("%lld %lld",&n,&m);
        printf("%lld\n",dp[n][m]);
    }
    return 0;
}
