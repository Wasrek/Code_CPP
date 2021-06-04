/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 100000007
long long dp[100010];
int main()
{
    long long q,n;
    dp[1]=1;
    for(int i=2;i<=100000;i++){
        dp[i]=(dp[i-1]+dp[i-2]+1)%MOD;
    }
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        printf("%lld\n",dp[n]%MOD);
    }
    return 0;
}