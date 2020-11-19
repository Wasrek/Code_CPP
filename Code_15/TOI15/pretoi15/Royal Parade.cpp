/*
    TASK:Royal Parade
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long v,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
long long mark[100010],dis[100010],tdis[100010],ans[100010];
vector<A> g[100010];
priority_queue< A >h;
int main(){
    long long n,m,i,j,u,v,w,a,b,c,d,tv,tw,all;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    scanf("%lld %lld",&a,&b);
    scanf("%lld %lld",&c,&d);
    for(i=1;i<=n;i++){
        dis[i]=tdis[i]=ans[i]=1e18;
    }
    dis[a]=0;
    tdis[b]=0;
    h.push({a,0});
    while(!h.empty()){
        tv=h.top().v;
        tw=h.top().w;
        h.pop();
        for(auto x:g[tv]){
            if(dis[x.v]<=tw+x.w)continue;
            dis[x.v]=tw+x.w;
            h.push({x.v,dis[x.v]});
        }
    }
    all=dis[b];
    h.push({b,0});
    while(!h.empty()){
        tv=h.top().v;
        tw=h.top().w;
        h.pop();
        for(auto x:g[tv]){
            if(tdis[x.v]<=tw+x.w)continue;
            tdis[x.v]=tw+x.w;
            h.push({x.v,tdis[x.v]});
        }
    }
    for(i=1;i<=n;i++){
        if(dis[i]+tdis[i]==all)mark[i]=1;//printf("%lld\n",i);
    }
    if(!mark[c])
    h.push({c,0});
    ans[c]=0;
    while(!h.empty()){
        tv=h.top().v;
        tw=h.top().w;
        h.pop();
        if(tv==d){
            printf("%lld",tw);
            return 0;
        }
        for(auto x:g[tv]){
            if(mark[x.v])continue;
            if(ans[x.v]<=tw+x.w)continue;
            ans[x.v]=tw+x.w;
            h.push({x.v,ans[x.v]});
        }
    }
    printf("-1\n");
    return 0;
}
