/*
    TASK:PT_Tree_Subset
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],mark[100010];
long long dp[2][100010];
vector< int > g[100010];
void dfs(int u){
    if(mark[u]) return ;
    mark[u]=1;
    dp[1][u]=a[u];
    for(auto x: g[u]){
        if(mark[x]) continue;
        dfs(x);
        dp[1][u]+=dp[0][x];
        dp[0][u]+=max(dp[0][x],dp[1][x]);
    }
    return ;
}
int main()
{
    int q,n,u,v;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<n;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1);
        printf("%lld\n",max(dp[1][1],dp[0][1]));
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        memset(mark,0,sizeof mark);
        memset(dp,0,sizeof dp);
    }
    return 0;
}