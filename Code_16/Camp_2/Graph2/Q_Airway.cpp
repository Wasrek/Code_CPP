/*
    TASK:Q_Airway
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,w,u;
    bool operator<(const A  & o) const{
        return w>o.w;
    }
};
vector< A >g[1010];
priority_queue< A > h;
int dis[2][1010];
int main()
{
    int u,v,w,n,m,st,en,a,b,t,k;
    scanf("%d %d",&n,&m);
    scanf("%d %d",&st,&en);
    scanf("%d %d %d %d",&a,&b,&t,&k);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
    }
    for(int i=0;i<=n;i++){
        dis[0][i]=dis[1][i]=2e9;
    }
    h.push({st,0,0});
    int i,use;
    while(!h.empty()){
        i=h.top().i;
        w=h.top().w;
        use=h.top().u;
        h.pop();
        if(i==a && w<=k && dis[1][b]>w+t && !use){
            dis[1][b]=w+t;
            h.push({b,w+t,1});
        }
        for(auto x: g[i]){
            if(dis[use][x.i]<=w+x.w) continue;
            dis[use][x.i]=w+x.w;
            h.push({x.i,dis[use][x.i],use});
        }
    }
    printf("%d\n",min(dis[0][en],dis[1][en]));
    return 0;
}