/*
    TASK:Taep's nitrous
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,w,k;
    bool operator <(const A & o) const{
        return w>o.w;
    }
};
struct B{
    long long u,w;
};
vector< B > g[5010];
priority_queue< A > h;
long long dis[5010][110];
int main()
{
    long long n,m,k,a,b,w;
    scanf("%lld %lld %lld",&n,&m,&k);
    while(m--){
        scanf("%lld %lld %lld",&a,&b,&w);
        g[b].push_back({a,w});
        g[a].push_back({b,w});
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
            dis[i][j]=1<<30;
        }
    }
    h.push({1,0,0});
    long long u,ha;
    long long ans=1<<30;
    while(!h.empty()){
        u=h.top().u;
        w=h.top().w;
        ha=h.top().k;
        h.pop();
        if(u==n){
            ans=min(ans,w);
        }
        if(ha==0 && u==n) break;
        for(auto x: g[u]){
            if(ha<k && dis[x.u][ha+1]>w+(x.w)/2){
                dis[x.u][ha+1]=w+(x.w)/2;
                h.push({x.u,dis[x.u][ha+1],ha+1});
            }
            if(dis[x.u][ha]>w+(x.w)){
                dis[x.u][ha]=w+(x.w);
                h.push({x.u,dis[x.u][ha],ha});
            }
        }
    }
    printf("%lld\n%lld\n%lld",dis[n][0],ans,dis[n][0]-ans);
    return 0;
}