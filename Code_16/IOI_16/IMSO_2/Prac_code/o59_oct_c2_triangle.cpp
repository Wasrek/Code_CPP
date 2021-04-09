/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long dp[110][110];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    dp[1][2]=dp[2][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((i==1 && j==2) || (i==2 && j==1)) continue;
            dp[i][j]+=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];
            dp[i][j]%=mod;
            for(int l=i-2;l>=max(0,i-k-1);l--){
                dp[i][j]+=dp[l][j-1]+1;
                dp[i][j]%=mod;
            }
            for(int l=j-2;l>=max(0,j-k-1);l--){
                dp[i][j]+=dp[i-1][l]+1;
                dp[i][j]%=mod;
            }
        }
    }
    printf("%lld\n",dp[n][n]);
    return 0;
}