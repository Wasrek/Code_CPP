/*
    TASK:FC_Golden_Age
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[5010][110],a[5010],n;
long long dfs(int u,int k){
    if(k==0 || u>n) return 0;
    if(dp[u][k]!=-1) return dp[u][k];
    long long ma=-1;
    for(int i=0;i<k;i++){
        ma=max(dfs(u*2,i)+dfs(u*2+1,k-i-1)+a[u],ma);
    }
    return dp[u][k]=ma;
}
int main()
{
    int k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    long long ans=-1;
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=n;i++){
        ans=max(dfs(i,k),ans);
    }
    printf("%lld\n",ans);
    return 0;
}