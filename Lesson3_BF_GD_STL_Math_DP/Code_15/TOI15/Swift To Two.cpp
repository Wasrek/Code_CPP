/*
    TASK:Swift To Two
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
long long dp[45],swift[45];
long long cal(long long a){
    long long ans=2*(a-a/2-1),i;
    for(i=2;i<41;i++){
        ans+=(swift[i+1]+1)*(a/dp[i]-a/dp[i+1]);
    }
    return ans;
}
int main(){
    long long a,b,i,j,sum=0;
    scanf("%lld %lld",&a,&b);
    dp[1]=1;
    for(i=2;i<=47;i++){
         dp[i]=dp[i-1]*(i/gcd(dp[i-1],i));
    }
    swift[2]=1;
    for(i=3;i<=41;i++){
        for(j=2;j<=41;j++){
            if(i%j){
                swift[i]=swift[j]+1;
                break;
            }
        }
    }
    printf("%lld\n",cal(b)-cal(a-1));
    return 0;
}
