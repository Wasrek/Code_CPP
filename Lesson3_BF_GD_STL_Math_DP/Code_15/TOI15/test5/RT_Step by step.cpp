/*
    TASK:RT_Step by step
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,w;
    bool operator<(const A&o)const{
    return w>o.w;
    }
};
vector< A > g[20010];
vector<int>ans;
priority_queue< A > h;
int d[20010],dt[20010];
int main(){
    int n,m,s,e,k,i,j,u,v,w,tu,tw;
    scanf("%d %d",&n,&m);
    scanf("%d %d %d",&s,&e,&k);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(i=0;i<n;i++){
        d[i]=dt[i]=1e9;
    }
    h.push({s,0});
    d[s]=0;
    while(!h.empty()){
        tu=h.top().u;
        tw=h.top().w;
        h.pop();
         for(auto x: g[tu]){
            if(d[x.u]<=tw+x.w)continue;
            d[x.u]=tw+x.w;
            h.push({x.u,d[x.u]});
         }
    }
    h.push({e,0});
    dt[e]=0;
    while(!h.empty()){
        tu=h.top().u;
        tw=h.top().w;
        h.pop();
         for(auto x: g[tu]){
            if(dt[x.u]<=tw+x.w)continue;
            dt[x.u]=tw+x.w;
            h.push({x.u,dt[x.u]});
         }
    }
    for(i=0;i<n;i++){
        if(d[i]+dt[i]>k)ans.push_back(i);
    }
    for(auto x: ans)printf("%d ",x);
    printf("\n");
}
