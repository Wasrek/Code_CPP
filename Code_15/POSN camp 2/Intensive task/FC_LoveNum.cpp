/*
    TASK:FC_LoveNum
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[1030];
int main(){
    long long n,num,temp,i,j,ans=0;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld",&num);
        temp=0;
        while(num>0){
            temp|=1<<(num%10);
            num/=10;
        }
        dp[temp]++;
    }
    for(i=0;i<1024;i++)
        for(j=i+1;j<1024;j++)
        if(i&j)
        ans+=(dp[i]*dp[j]);
    for(i=0;i<1024;i++)
    ans+=(dp[i]*(dp[i]-1)/2);
    printf("%lld\n",ans);
    return 0;
}
