/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    long long v,w,u;
    bool operator <(const A & o) const{
        return w>o.w;
    }
};
priority_queue< A > h;
vector< A > g[100010];
long long dis[2][100010];
int main()
{
    long long n,m,k,t,u,v,w,tv,tw,tu;
    scanf("%lld %lld %lld %lld",&n,&m,&k,&t);
    while(m--){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++) dis[0][i]=dis[1][i]=1<<30;
    dis[0][1]=0;
    dis[1][1]=0;
    h.push({1,0,1});
    while(!h.empty()){
        tv=h.top().v;
        tw=h.top().w;
        tu=h.top().u;
        h.pop();
        if(tw>t) continue;
        for(auto x: g[tv]){
            if(tw+x.w<dis[tu][x.v]){
                dis[tu][x.v]=tw+x.w;
                if(dis[0][x.v]>dis[tu][x.v]) dis[0][x.v]=dis[tu][x.v];
                h.push({x.v,dis[tu][x.v],tu});
            }
            if(tu && tw+k<dis[0][x.v]){
                dis[0][x.v]=tw+k;
                h.push({x.v,dis[0][x.v],0});
            }    
        }
    }
    dis[0][n]=min(dis[0][n],dis[1][n]);
    if(dis[0][n]>t){
            printf("No Honey TT\n");
        }else{
            printf("Happy Winnie the Pooh :3\n%lld",dis[0][n]);
    }
    // printf("No Honey TT\n");
    return 0;
}