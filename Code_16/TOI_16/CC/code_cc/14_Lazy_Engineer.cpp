/*
    TASK:Lazy Engineer
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int n,v,i,e;
    bool operator <(const A & o) const{
        if(v!=o.v) return v>o.v;
        else return i>o.i;
    }
};
struct B{
    long long v;
    int ma;
};
vector< A > g[1010];
B dis[2][1010];
priority_queue< A > h;
int main()
{
    int n,m,a,b,c,tn,tv,ti,te;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back({b,c,i});
        g[b].push_back({a,c,i});
    }
    for(int i=2;i<=n;i++){
        dis[0][i].v=dis[1][i].v=1e18;
    }
    h.push({1,0,1,1});
    while(!h.empty()){
        tn=h.top().n;
        tv=h.top().v;
        ti=h.top().i;
        te=h.top().e;
        h.pop();
        if(!te && tn==n){
            printf("%d %lld\n",ti,tv);
            return 0;
        }
        for(auto x: g[tn]){
            if(dis[te^1][x.n].v<tv+x.v || (dis[te^1][x.n].v==tv+x.v && dis[te^1][x.n].ma<=max(x.i,ti))) continue;
            dis[te^1][x.n].v=tv+x.v;
            dis[te^1][x.n].ma=max(x.i,ti);
            h.push({x.n,tv+x.v,dis[te^1][x.n].ma,te^1});
        }
    }
    return 0;
}