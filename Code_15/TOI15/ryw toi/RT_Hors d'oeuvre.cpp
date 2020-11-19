/*
    TASK:RT_Hors d'oeuvre
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[100010];
int depth[100010],from[100010],ans[100010],i=0;
void dfs(int u,int p){
    depth[u]=0;
    for(auto x:g[u]){
        if(x==p) continue;
        dfs(x,u);
        if(depth[u]<depth[x]){
            depth[u]=depth[x];
            from[u]=x;
        }
    }
    depth[u]++;
}
void dfs2(int u,int p,int ch){
    if(ch==0) ans[++i]=depth[u];
    for(auto x: g[u]){
        if(x==p) continue;
        if(x==from[u])dfs2(x,u,1);
        else dfs2(x,u,0);
    }
}
int main(){
    int n,u,v;
    scanf("%d",&n);
    n--;
    while(n--){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1);
    dfs2(1,-1,0);
    int j;
    printf("%d\n",i);
    sort(ans+1,ans+i+1);
    for(j=i;j>=1;j--){
        printf("%d\n",ans[j]);
    }
}
