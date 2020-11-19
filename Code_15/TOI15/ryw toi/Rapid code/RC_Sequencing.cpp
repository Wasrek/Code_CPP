/*
    TASK:RC_Sequencing
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long mop(long long a,long long b,long long c){
    if(b==1)return a%c;
    long long n=mop(a,b/2,c);
    n%=c;
    if(b%2==0)return (n*n)%c;
    if(b%2==1)return (((n*n)%c)*a)%c;
}
long long mod(long long n){
    return (n+1000000007)%1000000007;
}
long long dp[500100];
int main(){
    long long n,p,k,i,j;
    scanf("%lld %lld %lld",&n,&p,&k);
    for(i=p;i>=1;i--){
        dp[i]=mop(p/i,n,1000000007);
        for(j=i*2;j<=p;j+=i)dp[i]=mod(dp[i]-dp[j]);
    }
    printf("%lld\n",dp[k]);
}
