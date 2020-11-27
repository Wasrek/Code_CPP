/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100010][110],a[100010];
int main()
{
    int n,k,p;
    scanf("%d %d %d",&n,&k,&p);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]+=a[i-1];
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            dp[j][i]=dp[max(j-p,0)][i-1]+a[j]-a[max(0,j-p)];
            dp[j][i]=max(dp[j][i],dp[j-1][i]);
        }
    }
    printf("%d\n",dp[n][k]);
    return 0;
}