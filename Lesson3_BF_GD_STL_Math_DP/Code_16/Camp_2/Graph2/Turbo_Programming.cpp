/*
    TASK:Turbo Programming
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,w;
    bool operator<(const A & o) const{
        return w>o.w;
    }
};
priority_queue< A > h;
vector< A > g[1010];
int dis[1010];
int main()
{
    int n,m,q,u,v,w;
    scanf("%d %d %d",&n,&m,&q);
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
    }
    for(int i=1;i<=n;i++) dis[i]=1e9;
    dis[1]=0;
    h.push({1,0});
    int ti,tw;
    while(!h.empty()){
        ti=h.top().i;
        tw=h.top().w;
        h.pop();
        // if(tw>dis[ti])continue;
        for(auto x: g[ti]){
            if(dis[ti]+x.w<dis[x.i]){
                dis[x.i]=dis[ti]+x.w;
                h.push({x.i,dis[x.i]});
            }
        }
    }
    while(q--){
        scanf("%d",&u);
        if(dis[u]==1e9) printf("-1\n");
        else printf("%d\n",dis[u]);
    }
    return 0;
}