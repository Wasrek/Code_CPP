/*
    TASK:Notting land SCC Tarjan's
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
#define MN 100100
int idx[MN],lowlink[MN],com[MN],cnt=1,onstack[MN],cnt2=1;;
vector<int> g[MN];
stack<int> st;
void dfs(int u){
    idx[u]=lowlink[u]=cnt++;
    st.push(u);
    onstack[u]=1;
    for(auto x:g[u]){
        if(idx[x]==0){
            dfs(x);
            lowlink[u]=min(lowlink[u],lowlink[x]);
        }
        else if(onstack[x]){
            lowlink[u]=min(lowlink[u],idx[x]);
        }
    }
    if(idx[u]==lowlink[u]){
        while(!st.empty() && st.top()!=u){
            int now = st.top();st.pop();
            onstack[now]=0,com[now]=cnt2;
        }
        st.pop();
        onstack[u]=0; com[u]=cnt2; cnt2++;
    }
}
int main(){
    int n,m,k,d,i,v;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&d);
        while(d--){
            scanf("%d",&v);
            g[i].push_back(v);
        }
    }
    for(i=1;i<=n;i++)
        if(idx[i]==0)
        dfs(i);
    while(k--){
        scanf("%d %d",&i,&v);
        printf((com[i]==com[v])?"yes\n" : "no\n");
    }
    return 0;
}

