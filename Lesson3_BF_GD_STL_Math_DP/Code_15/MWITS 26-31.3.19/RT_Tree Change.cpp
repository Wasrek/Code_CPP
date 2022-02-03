/*
    TASK:RT_Tree Change
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>g[1010];
int child[1010],dp[1010];
void dfs(int i,int p)
{
    int mi1=1<<20,mi2=1<<20;
    for(auto x:g[i])
    {
        if(x==p)
            continue;
        dfs(x,i);
        child[i]+=child[x]+1;
        if(dp[x]-child[x]-1<=mi1){
            mi2=mi1;
            mi1=dp[x]-child[x]-1;
        }else if(dp[x]-child[x]-1<mi2){
            mi2=dp[x]-child[x]-1;
        }
    }
    dp[i]=min(child[i],child[i]+mi1+mi2);
}
int main()
{
    int q,n,i,j,u,v,Mi;
    scanf("%d",&q);
    while(q--)
    {
        Mi=1<<30;
        scanf("%d",&n);
        for(i=1; i<n; i++)
        {
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(i=1; i<=n; i++)
        {
            memset(child,0,sizeof child);
            memset(dp,0,sizeof dp);
            dfs(i,0);
            Mi=min(Mi,dp[i]);
        }
        printf("%d\n",Mi);
        for(i=1;i<=n;i++)g[i].clear();
    }
}
/*
3
7
4 5 4 2 1 2 1 3 4 6 3 7
*/
