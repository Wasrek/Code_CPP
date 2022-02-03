/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 29947
int dp[400][710];
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    a--;b--;c--;
    for(int i=1;i<=max(a,b);i++){
        for(int j=1;j<=b+c;j++){
            //dp(i,j)=dp[i-1][j-1]+dp[i][j-1]+dp[j][i-1]-dp[i-1][j-1]
            if(dp[i][j]) dp[i][j]+=dp[i-1][j-1]-1;
            dp[i][j]++;
            dp[i][j]%=MOD;
            dp[i][j]+=dp[i][j-1]+dp[i-1][j];
            dp[i][j]%=MOD;
            // printf("%d %d %d\n",i,j,dp[i][j]);
        }
        // printf("\n");
    }
    long long ans=0;
    for(int i=0;i<b;i++){
        for(int j=0;j<c;j++){
            ans+=(dp[a][i+j]+1)*(dp[b-i-1][c-j-1]+1);
            // printf("%d %d %d %d\n",i,j,dp[a][i+j]+1,dp[b-i-1][c-j-1]);
            ans%=MOD;
        }
    }
    // printf("%lld %d %d %d\n",ans,a,b,c);;
    ans+=dp[a][b+c]+1;ans%=MOD;
    printf("%lld\n",ans);
    return 0;
}