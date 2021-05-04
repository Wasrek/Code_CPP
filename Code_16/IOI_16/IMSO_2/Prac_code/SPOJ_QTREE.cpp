/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 10100
#define LOGN 15
struct A{
    int i,v;
};
vector< A > g[N];
A vec[N];
int sz[N],p[LOGN][N],pos[N],cha[N],dep[N],hd[N],idx,now,arr[N],seg[4*N],cost[N],n;
char str[10];
void dfs(int u,int la){
    p[0][u]=la;
    sz[u]=1;
    dep[u]= (la!=-1) ? dep[la]+1 : 1;
    for(int i=0;i<g[u].size();i++){
        if(g[u][i].i==la){
            swap(g[u][g[u].size()-1],g[u][i]);
        }
        if(g[u][i].i==la && i==g[u].size()-1) continue;
        dfs(g[u][i].i,u);
        sz[u]+=sz[g[u][i].i];
        if(sz[g[u][i].i] > sz[g[u][0].i]){
            swap(g[u][i],g[u][0]);
        }
    }
}
void hld(int u,int c){
    if(!hd[idx])hd[idx]=u;
    cha[u]=idx;
    pos[u]=++now;
    cost[now]=c;
    arr[now]=u;
    if(g[u][0].i == p[0][u]) return ;
    hld(g[u][0].i,g[u][0].v);
    for(int i=1;i<g[u].size();i++){
        if(g[u][i].i==p[0][u]) continue;
        idx++;
        hld(g[u][i].i,g[u][i].v);
    }
}
void build(int l,int r,int now){
    if(l==r){
        seg[now]=cost[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    seg[now]= seg[now*2]>seg[now*2+1] ? seg[now*2]:seg[now*2+1];
    return ;
}
void upd(int l,int r,int now,int a,int v){
    if(l>a || r<a) return ;
    if(l==r){
        seg[now]=v;
        return ;
    }
    int mid=(l+r)>>1;
    upd(l,mid,now*2,a,v);
    upd(mid+1,r,now*2+1,a,v);
    seg[now]= seg[now*2]>seg[now*2+1] ? seg[now*2]:seg[now*2+1];
    return ;
}
int que(int l,int r,int a,int b,int now){
    if(l>b || r<a) return -2e9;
    if(l>=a && r<=b) return seg[now];
    int mid=(l+r)>>1;
    return max(que(l,mid,a,b,now*2),que(mid+1,r,a,b,now*2+1));
}
int LCA(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    int dif=dep[v]-dep[u];
    for(int i=0;i<=LOGN;i++){
        if(dif>>i & 1) u=p[i][u];
    }
    if(u==v) return u;
    for(int i=LOGN;i>=0;i--){
        if(p[i][u]!=p[i][v]){
            u=p[i][u];
            v=p[i][v];
        }
    }
    return p[0][u];
}
int query(int u,int v){
    int now=-2e9;
    while(1){
        if(cha[u]==cha[v]){
            now=max(now,que(1,n,pos[v]+1,pos[u],1));
            return now;
        }
        now=max(now,que(1,n,pos[hd[cha[u]]],pos[u],1));
        u=p[0][hd[cha[u]]];
    }
}
int query_up(int u,int v){
    int lca=LCA(u,v);
    return max(query(u,lca),query(v,lca));
}
int main()
{
    int q,u,v,w;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back({v,w});
            g[v].push_back({u,w});
            vec[i]={u,v};
        }
        dfs(1,-1);
        for(int i=1;i<=LOGN;i++){
            for(int j=1;j<=n;j++){
                if(p[i-1][j]!=-1)p[i][j]=p[i-1][p[i-1][j]];
            }
        }
        memset(hd,0,sizeof hd);
        idx=1;now=0;
        hld(1,0);
        build(1,n,1);
        while(1){
            scanf("%s",str+1);
            if(str[1]=='D'){
                break;
            }else if(str[1]=='C'){
                scanf("%d %d",&u,&v);
                if(p[0][vec[u].i]==vec[u].v){
                    upd(1,n,1,pos[vec[u].i],v); 
                }else{
                    upd(1,n,1,pos[vec[u].v],v);
                }            
            }else{
                scanf("%d %d",&u,&v);
                printf("%d\n",query_up(u,v));
            }
        }
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
    }
    return 0;
}