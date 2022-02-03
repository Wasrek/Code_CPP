/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector< int > g[10100];
int va[10100],dp[10100][5];
void dfs(int now,int last){
    // printf("- %d %d\n",now,last);
    int sum0=0,sum1=0,midiff=2e9;
    for(auto x: g[now]){
        // printf("%d\n",x);
        if(x==last) continue;
        // printf("%d\n",x);
        dfs(x,now);
        sum0+=(dp[x][2]);
        sum1+=min(dp[x][0],dp[x][2]);
        midiff=min(midiff,dp[x][1]-dp[x][2]);
    }
    dp[now][0]=sum0;
    dp[now][1]=sum1+va[now];
    dp[now][2]=min(dp[now][1],sum0+midiff);
    // printf("%d %d %d %d\n",now,dp[now][0],dp[now][1],dp[now][2]);
    return ;
}
int main()
{
    int n,u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&va[i]);
    }
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1);
    printf("%d\n",dp[1][2]);
    return 0;
}