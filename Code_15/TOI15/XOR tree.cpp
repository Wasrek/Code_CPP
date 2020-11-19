/*
    TASK:XOR tree
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
};
vector< A > g[100010];
int p[100010],lvl[100010],xo[100010];
void dfs(int n,int l,int lv){
    for(auto x:g[n]){
        if(x.v==l)continue;
        xo[x.v]=xo[n]^x.w;
        lvl[x.v]=lv+1;
        p[x.v]=n;
        dfs(x.v,n,lv+1);
    }
}
int fin(int u,int v){
    if(p[u]==p[v])return p[u];
    if(lvl[u]>lvl[v])
    fin(p[u],v);
    else
    if(lvl[u]<lvl[v])
    fin(u,p[v]);
    else
    fin(p[u],p[v]);
}
int main(){
    int n,m,u,v,w,q,f,ans;
    scanf("%d %d",&n,&m);
    q=n-1;
    while(q--){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    xo[1]=0;
    lvl[1]=1;
    dfs(1,-1,1);
    q=m;
    while(q--){
        scanf("%d %d",&u,&v);
        f=fin(u,v);
        ans=xo[u]^xo[f]^xo[v]^xo[f];
        printf("%d\n",ans);
    }
    return 0;
}
