/*
    TASK:Brook_Connect
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1010],dp[1010];
int main()
{
    long long n,i,j;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(j=1;j<=n;j++){
        dp[j]=(dp[j-1]+dp[j-1]-dp[a[j]-1]+2+1000000007)%1000000007;
    }
    printf("%lld\n",dp[n]);

    return 0;
}
