/*
    TASK:Turbo Programming
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
vector<A> g[1010];
priority_queue< A > h;
int dis[1010],mark[1010];
int main()
{
    int n,m,q,s,e,w,tu,tw,a;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&s,&e,&w);
        g[s].push_back({e,w});
    }
    for(int i=1;i<=n;i++){
        dis[i]=1e9;
    }
    dis[1]=0;
    mark[1]=1;
    h.push({1,0});
    while(!h.empty()){
        tu=h.top().v;
        tw=h.top().w;
        h.pop();
        mark[tu]=1;
        for(auto x: g[tu]){
            if(!mark[x.v] && dis[x.v]>dis[tu]+x.w){
                dis[x.v]=dis[tu]+x.w;
                h.push({x.v,dis[x.v]});
            }
        }
    }
    while(q--){
        scanf("%d",&a);
        if(!mark[a])printf("-1\n");
        else printf("%d\n",dis[a]);
    }
    return 0;
}
