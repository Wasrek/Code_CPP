/*
    TASK:FC_Antler
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[100010];
long long play(long long n){
    if(n>=0 && n<4)return 1;
    if(dp[n]!=-1)return dp[n];
    if(n<0)return 0;
    return dp[n]=((play(n-1)%100003)+(play(n-4)%100003))%100003;
}
int main(){
    memset(dp,-1,sizeof dp);
    long long q,n,m,f,i,j,ans,now,k;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        printf("%lld\n",play(n));
    }
    return 0;
}
