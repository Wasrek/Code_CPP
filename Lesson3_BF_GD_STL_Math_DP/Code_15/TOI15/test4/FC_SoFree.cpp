/*
    TASK:FC_SoFree
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long dp[2100],temp[2100],cnt[2100],a[2100],mark[2100];
int main(){
    long long n,i,j,q;
    scanf("%lld",&n);
    dp[0]=1;
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        cnt[a[i]]++;
    }
    for(j=1;j<=n;j++){
        if(mark[a[j]])continue;
        mark[a[j]]=1;
        memset(temp,0,sizeof temp);
        for(i=0;i<=2050;i++){
            temp[i^a[j]]+=dp[i]*cnt[a[j]];
            temp[i^a[j]]%=mod;
        }
        for(i=0;i<=2050;i++){
            dp[i]+=temp[i];
            dp[i]%=mod;
        }
    }
    scanf("%lld",&q);
    dp[q]%=mod;
    printf("%lld\n",dp[q]);
}
