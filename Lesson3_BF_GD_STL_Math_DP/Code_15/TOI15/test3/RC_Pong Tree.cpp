/*
    TASK:RC_Pong Tree
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[400];
int main(){
    long long q,n,i,j,k;
    dp[0]=1;
    dp[1]=1;
    for(k=2;k<=350;k++){
        for(i=0;i<=k-1;i++){
            for(j=0;j<=k-i-1;j++){
                dp[k]+=(dp[i]*dp[j])%1000000007*dp[k-i-j-1];
                dp[k]%=1000000007;
            }
        }
    }
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        printf("%lld\n",dp[n]);
    }
}
