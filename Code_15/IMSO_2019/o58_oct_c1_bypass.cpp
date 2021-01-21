/*
    TASK:bypass
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector< long long > g[100010];
long long dp[100010][4];
long long n,ans;
void dfs(long long now,long long last){
    long long c=0,mc=0,mn=0;
    for(auto x: g[now]){
        if(x!=last){
            dfs(x,now);
            ans=max(ans,max(dp[x][0]*mn,max(dp[x][1]*mc,(n-dp[x][0])*dp[x][2])));
            mc=max(mc,dp[x][0]);
            mn=max(mn,dp[x][1]);
            c+=dp[x][0];
        }
    }
    dp[now][0]=c+1;
    dp[now][1]=mc;
    dp[now][2]=mn;
}
int main(){
    long long a,b;
    scanf("%lld",&n);
    for(long long i=1;i<n;i++){
        scanf("%lld %lld",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    printf("%lld\n",ans);
}