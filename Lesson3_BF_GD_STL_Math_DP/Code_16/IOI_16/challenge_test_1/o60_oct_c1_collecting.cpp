/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long v,w;
};
struct H{
    long long u,w,l;
    bool operator<(const H & o) const{
        if(w!=o.w) return w>o.w;
        return l<o.l;
    }
};
long long a[50100],ma[50100][35];
vector< A > g[50100];
priority_queue< H > h;
int main()
{
    long long n,m,l,s,t,u,v,w,la;
    scanf("%lld %lld %lld",&n,&m,&l);
    scanf("%lld %lld",&s,&t);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        for(int j=0;j<=l+1;j++) ma[i][j]=1<<30;
    }
    for(int i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w});
    }
    ma[s][0]=0;
    h.push({s,0,0});
    while(!h.empty()){
        u=h.top().u;
        w=h.top().w;
        l=h.top().l;
        h.pop();
        // printf("- %lld %lld %lld\n",u,w,l);
        if(min(l,a[t])==a[t] && u==t){
            printf("%lld\n",w);
            return 0;
        }
        for(auto x: g[u]){
            la=l;
            if(l==a[x.v]-1) la++;
            if(w+x.w >= ma[x.v][la]) continue;
            ma[x.v][la]=w+x.w;
            h.push({x.v,ma[x.v][la],la});
        }
    }
    return 0;
}