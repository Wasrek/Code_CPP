/*
    TASK:Turbo Programming
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    int v,w;
    bool operator <(const A&o) const {
    return w>o.w;
    }
};
priority_queue< A >dijk;
vector< A > g[1010];
int dis[1010];
int main()
{
    int m,n,q,s,e,w,i,u;
    scanf("%d %d %d",&n,&m,&q);
    while(m--){
        scanf("%d %d %d",&s,&e,&w);
        g[s].push_back({e,w});
    }
    for(i=0;i<=n;i++){
        dis[i]=1<<30;
    }
    dis[1]=0;
    dijk.push({1,0});
    while(!dijk.empty()){
        u=dijk.top().v,w=dijk.top().w;
        dijk.pop();
        for(auto x: g[u]){
            if(dis[u]+x.w<dis[x.v]){
                dis[x.v]=dis[u]+x.w;
                dijk.push({x.v,dis[x.v]});
            }
        }
    }
    while(q--){
        scanf("%d",&u);
        if(dis[u]==1<<30)printf("-1\n");
        else printf("%d\n",dis[u]);
    }
    return 0;
}
