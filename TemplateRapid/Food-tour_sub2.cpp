/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
#define N 60100
using namespace std;
struct A{
    int u;
    long long v;
    bool operator <(const A & o) const{
        return v>o.v;
    }
};
priority_queue< A > h;
unordered_map<int,int> mp;
int p[N];
long long food[510],dis[N];
bool res[N];
vector<pair<int,int>> g[N];
int findr(int i){
    if(p[i]==i) return i;
    return p[i]=findr(p[i]);
}
int main()
{
    int q,n,m,r,k,u,v,w,idx=0,now;
    long long ans=0;
    scanf("%d",&q);
    while(q--){
        idx=ans=0;
        scanf("%d %d %d %d",&n,&m,&r,&k);
        for(int i=1;i<=n;i++)p[i]=i;
        for(int i=1;i<n;i++){
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        for(int i=1;i<=r;i++){
            scanf("%d %d",&u,&v);
            p[u]=findr(p[v]);
            res[u]=res[v]=true;
        }
        for(int i=1;i<=n;i++){
            if(res[i] && !mp[findr(i)]) mp[findr(i)]=++idx;
        }
        while(k--){
            scanf("%d",&now);
            for(int i=1;i<=n;i++){
                dis[i]=3e9;
            }
            dis[now]=0;
            h.push({now,0});
            while(!h.empty()){
                u=h.top().u;
                v=h.top().v;
                h.pop();
                if(res[u] && food[mp[findr(u)]]<dis[u]) food[mp[findr(u)]]=dis[u];
                for(auto x: g[u]){
                    if(dis[x.first]>dis[u]+x.second){
                        dis[x.first]=dis[u]+x.second;
                        h.push({x.first,dis[x.first]});
                    }
                }
            }
        }
        for(int i=1;i<=m;i++) ans+=food[i],food[i]=0;
        printf("%lld\n",ans*2);
        for(int i=1;i<=n;i++){
            g[i].clear();
            res[i]=0;
        }
        mp.clear();
    }
    return 0;
}