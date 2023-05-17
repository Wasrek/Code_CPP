/*
    TASK:
    LANG: CPP
    AUTHOR: WasreK
    ALGO: 
    TYPE: BATCH
    SCORE: 
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[1010][3];
int main()
{
    long long q,n,p,mi,ma,a,l1,l2,ans;
    scanf("%lld",&q);
    for(int i=1;i<=q;i++){
        l1=l2=0;
        scanf("%lld %lld",&n,&p);
        for(int j=1;j<=n;j++){
            mi=2e9,ma=0;
            for(int k=1;k<=p;k++){
                scanf("%lld",&a);
                mi=min(mi,a);
                ma=max(ma,a);
            }
            dp[j][0]=dp[j][1]=ma-mi;
            dp[j][0]+=(min(dp[j-1][0]+abs(l1-ma),dp[j-1][1]+abs(l2-ma)));
            dp[j][1]+=(min(dp[j-1][0]+abs(l1-mi),dp[j-1][1]+abs(l2-mi)));
            l1=mi,l2=ma;
        }
        printf("Case #%lld: %lld\n",i,min(dp[n][0],dp[n][1]));
    }
    return 0;
}