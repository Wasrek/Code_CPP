/*
    TASK:Hotel
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000100];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=3;i<=n;i++)dp[i]=1<<30;
    dp[1]=500;
    dp[2]=800;
    dp[5]=1500;
    dp[15]=3000;
    for(i=3;i<=n;i++){
        if(i-1!=0){
            dp[i]=min(dp[i],dp[i-1]+500);
        }
        if(i-2!=0){
            dp[i]=min(dp[i],dp[i-2]+800);
        }
        if(i-5!=0){
            dp[i]=min(dp[i],dp[i-5]+1500);
        }
        if(i-15!=0){
            dp[i]=min(dp[i],dp[i-15]+3000);
        }
    }
    printf("%d\n",dp[n]);
}
