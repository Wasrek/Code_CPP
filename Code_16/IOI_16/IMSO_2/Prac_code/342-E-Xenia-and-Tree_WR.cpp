#include<bits/stdc++.h>
using namespace std;
vector<int> g[100010];
int h[100010],pa[25][100010],best[100010],pcen[100010],vis[100010],sz[100010];
void dfs(int i,int p){
    pa[0][i]=p;
    for(auto x : g[i]){
        if(x==p) continue;
        h[x]=h[i]+1;
        dfs(x,i);
    }
}
int lca(int u,int v){
    if(h[u]<h[v]) swap(u,v);
    int i,d=h[u]-h[v];
    for(i=0;i<=19;i++){
        if((d&(1<<i))!=0) u=pa[i][u];
    }
    if(u==v) return u;
    for(i=19;i>=0;i--){
        if(pa[i][u]==pa[i][v]) continue;
        u=pa[i][u];
        v=pa[i][v];
    }
    return pa[0][u];
}
int disup(int u,int v){
    return abs(h[u]-h[v]);
}
int dis(int u,int v){
    int l=lca(u,v);
    return disup(u,l)+disup(v,l);
}
int find_size(int i, int p) {
    if (vis[i]==1) return 0;
    sz[i] = 1;
    for (auto x: g[i]) {
        if (x == p) continue;
        sz[i] += find_size(x, i);
    }
    return sz[i];
}
int find_centroid(int i,int p,int s){
    for (auto x: g[i]) {
        if (x != p) {
            if (!vis[x] && sz[x] > s / 2) {
                return find_centroid(x, i, s);
            }
        }
    }
    return i;
}
void init_centroid(int v, int p) {
    find_size(v,-1);
    int c = find_centroid(v, -1, sz[v]);
    vis[c] = 1;
    pcen[c] = p;
    for (auto x: g[c]) {
        if (vis[x]==0){
            init_centroid(x, c);
        }
    }
}
void update(int v) {
    best[v] = 0;
    int u = v;
    while (pcen[u] != -1) {
        u = pcen[u];
        best[u] = min(best[u], dis(u, v));
    }
}
int query(int v) {
    int ans = best[v];
    int u = v;
    while (pcen[u] != -1) {
        u = pcen[u];
        ans = min(ans, best[u] + dis(u, v));
    }
    return ans;
}
int main(){
    int n,m,i,u,v,j,r,T;
    scanf("%d %d",&n,&m);
    for(i=0;i<n-1;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    h[1]=0;
    dfs(1,-1);
    for(i=1;i<=19;i++){
        for(j=1;j<=n;j++){
            pa[i][j]=pa[i-1][pa[i-1][j]];
        }
    }
    init_centroid(1,-1);
    memset(best,127,sizeof best);
    update(1);
    while(m--){
        scanf("%d %d",&T,&u);
        if(T==1) update(u);
        else printf("%d\n",query(u));
    }
return 0;
}
