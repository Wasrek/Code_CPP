/*
    TASK:55_Siren
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
};
struct B{
    int u,v,e;
    bool operator<(const B&o)const{
        return v>o.v;
    }
};
vector<A> g[50010];
priority_queue< B > h;
long long dis[50010],ch[50010];
A sf[50100];
int main()
{
    int n,m,k,a,b,c,d,e,u,v,tu,tv,te,i;
    scanf("%d %d %d",&n,&m,&k);
    while(m--){
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back({b,u});
        g[b].push_back({a,u});
    }
    for(i=1;i<n;i++)dis[i]=1<<30,ch[i]=1;
    for(i=1;i<=k;i++){
        scanf("%d %d",&sf[i].u,&sf[i].v);
        ch[sf[i].u]=0;
        h.push({sf[i].u,0,sf[i].v/2});
        dis[sf[i].u]=0;
    }
    while(!h.empty()){
        tu=h.top().u;
        tv=h.top().v;
        te=h.top().e;
        h.pop();
        for(auto x: g[tu]){
            if(dis[tu]+x.v<dis[x.u] && dis[tu]+x.v<=te){
                dis[x.u] = dis[tu]+x.v;
                ch[x.u]=0;
                h.push({x.u,dis[x.u],te});
            }
        }
    }
    for(i=1;i<n;i++)dis[i]=1<<30;
    h.push({n,0,0});
    dis[n]=0;
    while(!h.empty()){
        tu=h.top().u;
        tv=h.top().v;
        te=h.top().e;
        h.pop();
        for(auto x: g[tu]){
            if(dis[tu]!=1<<30 && dis[tu]+x.v<dis[x.u] && dis[tu]+x.v<=te){
                dis[x.u] = dis[tu]+x.v;
                ch[x.u]=max((long long)te,ch[x.u]);
                if(ch[x.u])
                h.push({x.u,dis[x.u],1});
                else h.push({x.u,dis[x.u],0});
            }
        }
    }
    for(i=1;i<n;i++){
            //printf("%lld ",dis[i]);
            if(ch[i]==0 || ch[n]==0)printf("1\n");
            else printf("0\n");
    }
    return 0;
}
/*
4 5 1
1 2 20
2 3 5
2 4 3
1 4 10
3 4 2
2 7
*/
