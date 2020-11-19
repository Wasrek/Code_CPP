/*
    TASK:Swift Puzzle
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long dp[4][100100];
void play(long long n,long long k){
    if(!k)  {dp[0][n]=1;return ;}
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
    dp[0][i]=dp[0][i-1]+dp[1][i-1]+dp[2][i-1];
    dp[0][i]%=mod;
    if(i-k>=0)
    dp[2][i]=dp[0][i-k];
    dp[2][i]%=mod;
    dp[1][i]=(dp[0][i-1]+dp[1][i-1])-dp[2][i];
    dp[1][i]%=mod;
    }
}
int main(){
    long long n,k,k1,k2,kk;
    scanf("%lld %lld",&n,&k);
    if(k>n){printf("0\n");return 0;}
    if(k==0)    {printf("1\n");return 0;}
    play(n,k);
    k1=(dp[0][n]+dp[1][n]+dp[2][n])%mod;
    memset(dp,0,sizeof dp);
    play(n,k-1);
    k2=(dp[0][n]+dp[1][n]+dp[2][n])%mod;
    kk=((k1-k2)+mod)%mod;
    printf("%lld\n",kk);
}
