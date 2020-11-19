/*
    TASK:RT_Key chain
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010],wh[100010],dp[100010];
int main()
{
    long long n,k,now=0;
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        wh[a[i]]=i;
    }
    for(int i=1;i<n;i++){
        dp[i]=(wh[i+1]-wh[i]+n)%n;
        now+=dp[i];
    }
    dp[n]=(wh[1]-wh[n]+n)%n;
    now+=dp[n];
    k--;
    long long ans=(now*(k/n));
    k%=n;
    for(int i=1;i<=k;i++)
        ans+=dp[i];
    printf("%lld\n", ans+wh[1]-1);
    // for(int i=1;i<=n;i++) printf("%lld ",dp[i]);
    return 0;
}