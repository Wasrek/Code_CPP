/*
    TASK:FC_RookPlace
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[100100];
int main(){
    long long n,i,j,p=1;
    scanf("%lld",&n);
    dp[1]=0;
    for(i=2;i<=n;i++){
        dp[i]=i*dp[i-1];
        //dp[i]+=(long long)(1e9+7);
        dp[i]%=(long long)(1e9+7);
        if(i%2==0){
            dp[i]++;
        }else{dp[i]--;}
        //dp[i]+=(long long)(1e9+7);
        dp[i]%=(long long)(1e9+7);
    }
    printf("%lld\n",dp[n]);
}
