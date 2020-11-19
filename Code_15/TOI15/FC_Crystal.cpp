/*
    TASK:FC_Crystal
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[1100];
int main(){
    long long n,i,j;
    dp[1]=1;
    dp[2]=1;
    for(i=3;i<=1001;i++){
        for(j=1;j<i;j++){
            dp[i]+=dp[j]*dp[i-j];
            dp[i]%=10001;
        }
    }
    scanf("%lld",&n);
    n++;
    printf("%lld\n",dp[n]);
}
