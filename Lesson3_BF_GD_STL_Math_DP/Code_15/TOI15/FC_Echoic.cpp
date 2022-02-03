/*
    TASK:FC_Echoic
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long dp[10010][10010],a[10010];
int main()
{
    long long n,i,j,k;
    scanf("%lld",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
    }
    if(a[1]!=0 && a[1]!=-1)
    {
        printf("0\n");
        return 0;
    }
    dp[1][0]=1;
    for(i=2; i<=n; i++)
    {
        if(a[i]==-1)
        {
            if(i-1<0)continue;
            for(j=0; j<=min(i,n-i+1); j++){
                dp[i][j]=dp[i-1][j]+dp[i-1][j+1];
                if(j-1>=0)dp[i][j]+=dp[i-1][j-1],dp[i][j]%=mod;
                else dp[i][j]%=mod;
            }
        }
        else{
            j=a[i];
            if(i-1<0)continue;
            dp[i][j]=dp[i-1][j]+dp[i-1][j+1];
            if(j-1>=0)dp[i][j]+=dp[i-1][j-1],dp[i][j]%=mod;
            else dp[i][j]%=mod;
        }
    }
    printf("%lld\n",dp[n][0]);
}
