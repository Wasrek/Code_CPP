/*
    TASK:Durian Binary Tree
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int n;
struct A{
    int v,w;
};
int p[110],dp[110][110];
vector< A > g[110];
vector<int> chi[110];
void dfs(int i){
    for(auto x : g[i]){
        if(p[x.v]!=-1) continue;
        else{
            p[x.v]=x.w;
            chi[i].push_back(x.v);
            dfs(x.v);
        }
    }
    return ;
}
int play(int now,int k){
    if(dp[now][k]!=-1) return dp[now][k];
    if(!k) return 0;
    if(chi[now].size()==0) return p[now];
    if(chi[now].size()==1) return dp[now][k]=play(chi[now][0],k-1)+p[now];
    int ma=-1;
    for(int i=0;i<k;i++){
        ma=max(ma,play(chi[now][0],i)+play(chi[now][1],k-i-1)+p[now]);
    }
    return dp[now][k]=ma;
}
int main()
{
    int k;
    scanf("%d %d",&n,&k);
    int u,v,w;
    for(int i=1;i<n;i++){
    scanf("%d %d %d",&u,&v,&w);
    g[u].push_back({v,w});
    g[v].push_back({u,w});
    }
    memset(p,-1,sizeof p);
    p[1]=0;
    memset(dp,-1,sizeof dp);
    dfs(1);
    int ans=play(1,k+1);
    printf("%d\n",ans);
    return 0;
}