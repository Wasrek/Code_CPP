/*
    TASK:Notty Land
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[100100],gt[100100];
int mark[100100],num[100100],cnt=0;
stack<int> st;
void dfs(int u){
    if(mark[u])return ;
    mark[u]=1;
    for(auto x:g[u]){
        if(!mark[x])
            dfs(x);
    }
    st.push(u);
}
void dfs2(int u){
    if(mark[u]) return ;
    mark[u]=1;
    num[u]=cnt;
    for(auto x:gt[u]){
        if(!mark[x])
            dfs2(x);
    }
}
int main(){
    int n,m,k,i,d,v,u;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&d);
        while(d--){
            scanf("%d",&v);
            g[i].push_back(v),gt[v].push_back(i);
        }
    }
    for(i=1;i<=n;i++){
        if(!mark[i])
            dfs(i);
    }
    memset(mark,0,sizeof mark);
    while(!st.empty()){
        u=st.top();st.pop();
        if(mark[u])continue;
        num[u]=++cnt;
        dfs2(u);

    }
    while(k--){
        scanf("%d %d",&u,&v);
        printf((num[u]==num[v])?"yes\n":"no\n");
    }
    return 0;
}
