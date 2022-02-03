#include<bits/stdc++.h>
using namespace std;
long long dp[10001][10001],a[10100];
int main()
{
    long long i,n,k,j,ans=0;
    dp[0][0]=1;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++){
        dp[i][0]=dp[i][i]=1;
        for(j=1;j<i;j++)
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%1000000007;
    }
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a,a+n,greater<int>());
    for(i=0;i<=n-k;i++)
    {
        ans+= (long long)a[i]*dp[n-i-1][k-1]%1000000007;
    }
    printf("%lld\n",ans%1000000007);

    return 0;
}
