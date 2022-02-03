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
vector< A > g[2020],vec;
struct H{
    long long u,w,cnt;
    bool operator<(const H & o) const{
        if(w!=o.w) return w>o.w;
        return cnt>o.cnt;
    }
};
priority_queue< H > h;
long long dis[2020][2020];
int main()
{
    long long n,m,s,e,u,v,w,cnt,q,k,ans;
    scanf("%lld %lld %lld %lld",&n,&s,&e,&m);
    for(int i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        if(u==e) continue;
        g[u].push_back({v,w});
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dis[i][j]=1e18;
        }
        dis[s][i]=0;
    }
    h.push({s,0,0});
    while(!h.empty()){
        u=h.top().u;
        w=h.top().w;
        cnt=h.top().cnt;
        h.pop();
        // printf("%lld %lld %lld\n",u,w,cnt);
        for(auto x: g[u]){
            if(dis[x.u][cnt+1]<=w+x.w) continue;
            dis[x.u][cnt+1]=w+x.w;
            h.push({x.u,w+x.w,cnt+1});
        }
    }
    for(int i=1;i<=n;i++){
        dis[e][i]=min(dis[e][i-1],dis[e][i]);
        if(dis[e][i]!=dis[e][i-1])vec.push_back({dis[e][i],i-1});
        // printf("%lld ",dis[e][i]);
    }
    // for(auto x: vec){
    //     printf("%lld %lld\n",x.u,x.w);
    // }
    scanf("%lld",&q);
    for(int i=1;i<=q;i++){
        scanf("%lld",&k);
        ans=1e18;
        for(auto x: vec){
            ans=min(ans,x.u+(x.w*k));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
8 0 7 14
0 1 10
0 3 14
0 4 8
1 2 2
2 7 2
2 3 4
3 7 15
3 4 9
5 3 7
5 7 2
4 5 5
4 6 1
6 5 1
6 4 3
4
0 10 2 30
*/