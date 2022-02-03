/*
    TASK:Notty Land_Tarjans
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define MN 100100
int idx[MN],lowlink[MN],scc[MN],cnt=1,cnt2=1,onstack[MN];
vector<int> g[MN];
stack<int>st;
void dfs(int u){
    idx[u]=lowlink[u]=cnt++,onstack[u]=1;
    st.push(u);
    for(auto x:g[u]){
        if(idx[x]==0){//never go
            dfs(x);
            lowlink[u]=min(lowlink[u],lowlink[x]);
        }else if(onstack[x]){//working on it
            lowlink[u]=min(lowlink[u],idx[x]);
        }
    }
    if(idx[u]==lowlink[u]){
        while(!st.empty() && st.top()!=u){
            int i=st.top();st.pop();
            scc[i]=cnt2;
            onstack[i]=0;
        }
        st.pop();
        scc[u]=cnt2++;
        onstack[u]=0;
    }
}
int main(){
    int n,m,k,i,j,r;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&j);
        while(j--){
            scanf("%d",&r);
            g[i].push_back(r);
        }
    }
    for(i=1;i<=n;i++){
        if(!idx[i])
            dfs(i);
    }
    while(k--){
        scanf("%d %d",&i,&j);
        if(scc[i]==scc[j])printf("yes\n");
        else printf("no\n");
    }
}
