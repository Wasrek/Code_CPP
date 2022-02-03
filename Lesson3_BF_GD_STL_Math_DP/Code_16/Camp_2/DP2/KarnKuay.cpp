/*
    TASK:KarnKuay
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010],dp[100010];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(i>=3) dp[i]=max(dp[i-1],dp[i-3]+a[i]);
    }
    printf("%lld\n",dp[n]);
    return 0;
}