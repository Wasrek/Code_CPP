/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod ll(1e9+7)
long long dp[100010];
int main()
{
    long long n;
    scanf("%lld",&n);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]*i)%mod;
        if(i%2)dp[i]--;
        else dp[i]++;
    }
    dp[n]%=mod;
    printf("%lld\n",dp[n]%mod);
    return 0;
}