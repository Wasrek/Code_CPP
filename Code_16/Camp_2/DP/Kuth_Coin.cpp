/*
    TASK:Kuth Coin
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000003
int a[7]={0,1,5,10,25,50},dp[100010];
int main()
{
    dp[0]=1;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=100000;j++){
            if(j-a[i]>=0)
            dp[j]+=dp[j-a[i]]%mod;
            dp[j]%=mod;
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