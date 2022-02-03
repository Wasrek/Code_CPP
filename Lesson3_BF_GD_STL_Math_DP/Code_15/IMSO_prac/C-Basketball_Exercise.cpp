/*
    TASK:C-Basketball_Exercise
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[100010][3],a[100010],b[100010];
int main()
{
    long long n,i;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&b[i]);
    }
    for(i=1;i<=n;i++){
        if(i>1){
        dp[i][0]=a[i]+max(dp[i-1][2],max(dp[i-1][1],dp[i-2][0]));
        dp[i][1]=b[i]+max(dp[i-1][2],max(dp[i-2][1],dp[i-1][0]));
        dp[i][2]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        }
        else{
            dp[i][0]=a[i]+max(dp[i-1][2],dp[i-1][1]);
        dp[i][1]=b[i]+max(dp[i-1][2],dp[i-1][0]);
        dp[i][2]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        }
    }
    long long ans=max(dp[n][0],max(dp[n][1],dp[n][2]));
    printf("%lld",ans);
}
