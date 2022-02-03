/*
    TASK:82_Peatt Tree
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010];
int play(int n){
    if(dp[n]) return dp[n];
    int ans=0,i;
    for(i=0;i<n;i++){
        if(!dp[i])dp[i]=play(i)%9973;
        if(!dp[n-1-i]) dp[n-1-i]=play(n-1-i)%9973;
        ans+=(dp[i]*dp[n-1-i])%9973;
    }
    return dp[n]=ans%9973;
}
int main(){
    int q,n;
    dp[0]=dp[1]=1;
    q=play(1000);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        printf("%d\n",dp[n-1]);
    }
    return 0;
}
