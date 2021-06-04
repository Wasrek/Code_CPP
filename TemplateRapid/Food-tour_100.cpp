/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 60100
struct A{
    long long ht,fd[510];
};
A town[N];
int p[N],idx=0,mp[N];
long long food[510];
bool hotel[N],res[N];
vector< pair<int,int> > g[N];
int findr(int i){
    if(p[i]==i) return i;
    return p[i]=findr(p[i]);
}
void dfs(int now,int la){
    town[now].ht=-3e9;
    for(int i=1;i<=idx;i++)town[now].fd[i]=-3e9;
    if(res[now]) town[now].fd[mp[findr(now)]]=0;
    if(hotel[now]) town[now].ht=0;
    for(auto x: g[now]){
        if(x.first==la) continue;
        dfs(x.first,now);
        for(int i=1;i<=idx;i++){
            food[i]=max(food[i],town[now].ht+town[x.first].fd[i]+x.second);
            food[i]=max(food[i],town[now].fd[i]+town[x.first].ht+x.second);
            town[now].fd[i]=max(town[now].fd[i],town[x.first].fd[i]+x.second);
        }
        town[now].ht=max(town[now].ht,town[x.first].ht+x.second);
    }
    return ;
}
int main()
{
    int q,n,m,r,k,u,v,w;
    scanf("%d",&q);
    while(q--){
        idx=0;
        scanf("%d %d %d %d",&n,&m,&r,&k);
        for(int i=1;i<n;i++){
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        for(int i=1;i<=n;i++) p[i]=i;
        for(int i=1;i<=r;i++){
            scanf("%d %d",&u,&v);
            p[findr(u)]=findr(v);
            res[u]=res[v]=true;
        }
        for(int i=1;i<=n;i++){
            if(res[i] && !mp[findr(i)]) mp[findr(i)]=++idx;
        }
        for(int i=1;i<=k;i++){
            scanf("%d",&u);
            hotel[u]=1;
        }
        dfs(1,-1);
        long long ans=0;
        for(int i=1;i<=idx;i++){
            ans+=food[i];
            food[i]=0;
        }
        printf("%lld\n",ans*2);
        for(int i=1;i<=n;i++){
            g[i].clear();
            mp[i]=0;
            res[i]=hotel[i]=0;
        }
    }
    return 0;
}