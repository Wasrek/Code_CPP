/*
    TASK:Fast Contest
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[10100],gt[10100];
int mark[10100],dp[10100],n,m,u,v;
queue<int> Q;
void dfs(int u){
    mark[u]=1;
    for(auto x:g[u])
        if(!mark[x])
            dfs(x);
    Q.push(u);
}
int main(){
    int i,ch=0;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&u,&v);
        g[u].push_back(v),gt[v].push_back(u);
    }
    for(i=1;i<=n;i++)
        if(!mark[i])
        dfs(i);
    dp[2]=1;
    while(!Q.empty()){
        u=Q.front();Q.pop();
        for(auto x:gt[u]){
            dp[x]+=dp[u];
            if(dp[x]>1000000000) ch=1;
            dp[x]%=1000000000;
        }
    }
    if(ch) printf("%09d\n",dp[1]);
    else printf("%d\n",dp[1]);
}
/*
6 7
1 3
1 4
3 2
4 2
5 6
3 4
6 5
*/