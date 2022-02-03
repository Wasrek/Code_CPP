/*
    TASK:Stair
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[5010];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            if(dp[j-i]){
                dp[j]+=(dp[j-i]%k);
                dp[j]%=k;
            }
        }
    }
    printf("%lld\n",(dp[n]-1)%k);
    return 0;
}