#include<bits/stdc++.h>
using namespace std;
int close[100100];
vector<int> g[3][100100],ans;
vector<pair<int,int>> opr;
int vis[3][100100];
int wait[3][100100];
void dfs(int u,int st)
{
    vis[st][u]=1;
    for(auto x:g[st][u]){
        if(!vis[st][x] && !close[x])
            dfs(x,st);
        else if(!vis[st][x])
            wait[st][x]=1;
    }
    return;
}
int main()
{
    int n,m,q,u,v,op;
    scanf("%d %d %d",&n,&m,&q);
    while(m--){
        scanf("%d %d",&u,&v);
        g[0][u].push_back(v); g[1][v].push_back(u);
    }
    while(q--){
        scanf("%d %d",&op,&u);
        opr.push_back({op,u});
        if(op==1) close[u]=1;
    }
    reverse(opr.begin(),opr.end());
    dfs(1,0); dfs(n,1);
    for(auto x:opr){
        if(x.first==1){
            close[x.second]=0;
            if(wait[0][x.second])  dfs(x.second,0);
            if(wait[1][x.second]) dfs(x.second,1);
        }else if(x.first==2){
            if(vis[0][x.second] && vis[1][x.second]) ans.push_back(1);
            else ans.push_back(0);
        }
    }
    for(int i=ans.size()-1;i>=0;i--)
        printf("%d\n",ans[i]);
    return 0;
}