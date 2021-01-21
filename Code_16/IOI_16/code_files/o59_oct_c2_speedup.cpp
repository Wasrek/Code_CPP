/*
    TASK:o59_oct_c2_speedup
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
    long long u,w,k,la;
    bool operator < (const H & o) const{
        if(w!=o.w) return w>o.w;
        return k>o.k;
    }
};
vector< A > g[80100];
long long ha[80100];
long long ma[80100][10];
priority_queue< H > h;
int main()
{
    long long n,m,l,k,mak,u,v,w,la;
    scanf("%lld %lld %lld %lld",&n,&m,&l,&mak);
    for(int i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w});
    }
    for(int i=1;i<=l;i++){
        scanf("%lld",&u);
        ha[u]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=mak;j++){
            ma[i][j]=1<<30;
        }
    }
    ma[1][0]=0;
    h.push({1,0,0,0});
    while(!h.empty()){
        u=h.top().u;
        w=h.top().w;
        k=h.top().k;
        la=h.top().la;
        h.pop();
        // printf("%d %d %d %d\n",u,w,k,la);
        if(u==n){
            printf("%lld\n",w);
            return 0;
        }
        for(auto x: g[u]){
            if(ma[x.u][k]<=w+(x.w/(1<<k))) continue;
            ma[x.u][k]=w+(x.w/(1<<k));
            h.push({x.u,ma[x.u][k],k,la});
        }
        if(u==la || k==mak || !ha[u]) continue;
        for(auto x: g[u]){
            if(ma[x.u][k+1]<=w+(x.w/(1<<(k+1)))) continue;
            ma[x.u][k+1]=w+(x.w/(1<<(k+1)));
            h.push({x.u,ma[x.u][k+1],k+1,u});
        }
    }
    return 0;
}