/*
    TASK:Loose summation
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000003
int dp[2010];
int main()
{
    dp[0]=1;
    for(int i=1;i<=2000;i++){
        for(int j=2000;j>=i;j--){
            if(dp[j-i]){
                dp[j]+=dp[j-i]%mod;
                dp[j]%=mod;
            }
        }
    }
    int q,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        printf("%d\n",dp[n]%mod);
    }
    return 0;
}