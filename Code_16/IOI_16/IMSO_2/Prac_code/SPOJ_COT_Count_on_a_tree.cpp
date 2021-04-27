/*
    TASK:COT - Count on a tree
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100100
struct A{
    int cnt,l,r;
} seg[24*N];
pair<int,int> w[N];
vector< int > g[N];
int dep[N],root[N],n,idx=0,p[25][N];
unordered_map< int,int > mp;
void build(int l,int r,int &a,int b,int id){
    a=b;
    if(id<l || id>r) return ;
    a=++idx;
    seg[a]=seg[b];
    if(l==r){
        seg[a]={1,0,0};
        return ;
    }
    int L,R,mid=(l+r)>>1;
    build(l,mid,L,seg[a].l,id);
    build(mid+1,r,R,seg[a].r,id);
    seg[a]={seg[L].cnt+seg[R].cnt,L,R};
    return ;
}
void dfs(int now,int pa){
    p[0][now]=pa;
    build(1,n,root[now],root[p[0][now]],mp[now]);
    dep[now]= (pa==0) ? 0:dep[pa]+1;
    for(auto x: g[now]){
        if(x==pa) continue;
        dfs(x,now);
    }
    return ;
}
int lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    int dif=dep[u]-dep[v];
    for(int i=0;i<19;i++){
        if(dif>>i & 1) u=p[i][u];
    }
    if(u==v) return u;
    for(int i=18;i>=0;i--){
        if(p[i][u]!=p[i][v]) u=p[i][u],v=p[i][v];
    }
    return p[0][u];
}
int que(int l,int r,int a,int b,int c,int d,int k){
    if(l==r){
        return w[l].first;
    }
    int mid=(l+r)>>1;
    int cou=seg[seg[a].l].cnt+seg[seg[b].l].cnt-seg[seg[c].l].cnt-seg[seg[d].l].cnt;
    if(k<=cou){
        return que(l,mid,seg[a].l,seg[b].l,seg[c].l,seg[d].l,k);
    }else{
        return que(mid+1,r,seg[a].r,seg[b].r,seg[c].r,seg[d].r,k-cou);
    }
}
int main()
{
    int m,u,v,k;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i].first);
        w[i].second=i;
    }
    sort(w+1,w+1+n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        mp[w[i].second]=i;
    }
    // for(int i=1;i<=n;i++) cout<<mp[i]<<" ";
    mp[w[n].second]=n;
    seg[0]={0,0,0};
    dfs(1,0);
    for(int i=1;i<19;i++){
        for(int j=1;j<=n;j++){
            p[i][j]=p[i-1][p[i-1][j]];
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&k);
        // path(u,v) = path(root,u) + path(root,v) - path(root,lca(u,v)) - path(root,pa[lca(u,v)])
        printf("%d\n",que(1,n,root[u],root[v],root[lca(u,v)],root[p[0][lca(u,v)]],k));
    }
    return 0;
}