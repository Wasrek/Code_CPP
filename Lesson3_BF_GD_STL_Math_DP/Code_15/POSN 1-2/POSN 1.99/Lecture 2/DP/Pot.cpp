/*
    TASK:Pot
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100],qs[100100];
int main(){
    dp[1]=1,qs[0]=1,qs[1]=2;
    int i,n,k;
    scanf("%d %d",&n,&k);
    for(i=2;i<=n;i++){
        if(i-k-1>=0) dp[i]=qs[i-1]-qs[i-k-1];
        else         dp[i]=qs[i-1];
        dp[i]+=2009,dp[i]%=2009;
        qs[i]=dp[i]+qs[i-1];
        qs[i]+=2009,dp[i]%=2009;
    }
    printf("%d\n",dp[n]);
    return 0;
}
