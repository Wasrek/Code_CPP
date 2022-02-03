/*
    TASK:RT_Stair
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long dp[3][2000010];
int main(){
    long long i,j,n;
    dp[0][0]=1;
    dp[1][0]=1;
    dp[0][1]=1;
    //printf("----------");
    for(i=2;i<=2000000;i++){
        //printf("%d",i);
        dp[0][i]+=(dp[0][i-1]+dp[0][i-2]);
        dp[0][i]%=mod;
    }
    //printf("----------");
    dp[1][1]=3;
    for(i=2;i<=1000000;i++){
        dp[1][i]+=dp[0][i*2];
        dp[1][i]+=dp[0][i];
        dp[1][i]%=mod;
        dp[1][i]+=(dp[1][i-1]+dp[1][i-2]-dp[0][i-1]-dp[0][i-2]);
        dp[1][i]+=2*mod;
        dp[1][i]%=mod;
    }
    int q;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        printf("%lld\n",dp[1][n]%mod);
    }
    return 0;
}
