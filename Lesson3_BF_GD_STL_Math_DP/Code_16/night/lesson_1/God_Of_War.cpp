/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,w;
};
struct H{
    long long u,w;
    bool operator<(const H & o) const{
        return w>o.w;
    }
};
vector< A > g[100100];
long long dis[100100],dis2[100100];
priority_queue< H > h;
int main()
{
    long long n,m,s,e,u,v,w,ma=0,summ=0;
    scanf("%lld %lld %lld %lld",&n,&m,&s,&e);
    for(int i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        summ+=w;
    }
    for(int i=0;i<=n;i++){
        dis2[i]=dis[i]=1<<30;
    }
    dis[s]=0;
    h.push({s,0});
    while(!h.empty()){
        u=h.top().u;
        w=h.top().w;
        h.pop();
        for(auto x: g[u]){
            if(w+x.w>dis[x.u]) continue;
            dis[x.u]=w+x.w;
            h.push({x.u,w+x.w});
        }
    }
    h.push({e,0});
    dis2[e]=0;
    while(!h.empty()){
        u=h.top().u;
        w=h.top().w;
        h.pop();
        for(auto x: g[u]){
            if(w+x.w>dis2[x.u]) continue;
            dis2[x.u]=w+x.w;
            h.push({x.u,w+x.w});
        }
    }
    for(int i=0;i<n;i++){
        for(auto x: g[i]){
            ma=max(ma,summ-dis[i]-dis2[x.u]);
        }
    }
    printf("%lld\n",ma);
    return 0;
}