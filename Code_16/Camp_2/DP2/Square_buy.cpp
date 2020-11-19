/*
    TASK:Square buy
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[100010];
int main()
{
    int q,n,m;
    scanf("%d",&q);
    for(int i=1;i<=100000;i++) dp[i]=1<<30;
    dp[0]=0;
    for(int i=1;i<=320;i++){
        for(int j=(i*i);j<=100000;j++){
            dp[j]=min(dp[j],dp[j-(i*i)]+1);    
        }
    }
    while(q--){
        scanf("%d %d",&n,&m);
        printf("%lld\n",dp[n]%m);
    }
    return 0;
}