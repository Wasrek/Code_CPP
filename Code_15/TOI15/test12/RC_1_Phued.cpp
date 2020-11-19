/*
    TASK:RC_1 Phued
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010],f[100010],b[100010],mark[100010],dp[100010];
int main(){
    long long n,i,ma=0,q,j;
    scanf("%lld",&q);
    while(q--){
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(i=n;i>=1;i--){
        b[i]=1;
        if(a[i+1]==a[i]+1)b[i]+=b[i+1];
    }
    memset(dp,-1,sizeof dp);
    b[n+1]=0;
    f[n+1]=0;
    for(i=1;i<=n;i++){
        f[i]=1;
        if(a[i]-1==a[i-1])f[i]+=f[i-1];
        ma=max(f[i],ma);
        if(f[i]==1 && f[i-1]>1)mark[i-1]=1;
        if(b[i]==1 && b[i+1]>1)dp[i]=i+1;
    }
    for(i=n;i>=1;i--){
        if(dp[i]==-1)dp[i]=dp[i+1];
    }
    for(i=1;i<=n;i++)printf("%lld ",f[i]);
    printf("\n");
    for(i=1;i<=n;i++)printf("%lld ",b[i]);
    printf("\n");
    for(i=1;i<=n;i++)printf("%lld ",mark[i]);
    printf("\n");
    for(i=1;i<=n;i++)printf("%lld ",dp[i]);
    printf("\n");
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
        if(dp[j]!=-1 && a[i]+1==a[dp[j]])ma=max(ma,f[i]+b[dp[j]]);
        }
    }
    printf("%lld\n",ma);
    memset(mark,0,sizeof mark);
    }
}
/*
10
9 2 3 4 9 8 7 5 6 1
*/
