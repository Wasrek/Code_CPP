/*
    TASK:Invermake
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010][10010];
int main()
{
    int n,d;
    scanf("%d %d",&n,&d);
    for(int i=0;i<=d;i++) dp[1][i]=1;
    for(int i=2;i<=n;i++){
        dp[i][0]=1;
        for(int j=1;j<=d;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
            if(j-i>=0) dp[i][j]-=dp[i-1][j-i];
            dp[i][j]%=1000000007;
            dp[i][j]+=1000000007;
            dp[i][j]%=1000000007;
        }
    }
    printf("%d\n",(((dp[n][d]-dp[n][d-1])%1000000007)+1000000007)%1000000007);
    return 0;
}