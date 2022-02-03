/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long dp[110][110];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    dp[1][2]=dp[2][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((i==1 && j==2) || (i==2 && j==1)) continue;
            dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            dp[i][j]%=MOD;
            for(int x=i-2;x>=max(0,i-k-1);x--){
                dp[i][j]+=dp[x][j-1]+1;
                dp[i][j]%=MOD;
            }
            for(int y=j-2;y>=max(0,j-k-1);y--){
                dp[i][j]+=dp[i-1][y]+1;
                dp[i][j]%=MOD;
            }
        }
    }
    printf("%lld\n",dp[n][n]);
    return 0;
}