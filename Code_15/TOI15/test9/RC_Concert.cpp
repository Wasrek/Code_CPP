/*
    TASK:RC_Concert
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,w,i;
};
struct B{
    int u,w;
    bool operator<(const B&o)const{
    return w>o.w;
    }
};
vector< A > g[300010];
int dis[300010],l[300010],qs[300010],tdis[300010],mark[300010],li[300010],ma[300010];
priority_queue< B > h;
int main(){
    int n,m,u,v,w,i,j,cou=1;
    scanf("%d",&n);
    m=n-1;
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w,i});
        g[v].push_back({u,w,i});
        l[u]++;
        l[v]++;
        li[u]=i;
        li[v]=i;
        if(v==1 && u==1)ma[i]=1;
    }
    for(i=1;i<=n;i++){
        if(l[i]!=1)l[i]=0;
        dis[i]=1e9;
        tdis[i]=1e9;
    }
    h.push({1,0});
    //printf("%d\n",h.top().u);
    dis[1]=0;
    while(!h.empty()){
        u=h.top().u;
        w=h.top().w;
        h.pop();
        //printf("--- %d %d\n",u,w);
        for(auto x: g[u]){
            if(dis[x.u]<=w+x.w)continue;
            dis[x.u]=w+x.w;
            h.push({x.u,w+x.w});
        }
    }
    for(i=2;i<n;i++){
        if(l[i]){
        if(dis[i]<dis[n])cou++;
        }
        //printf("%d ",dis[i]);
    }
    //printf("\n");
    printf("%d\n",cou);
    h.push({n,0});
    tdis[n]=0;
    while(!h.empty()){
        u=h.top().u;
        w=h.top().w;
        h.pop();
        if(u==1)break;
        for(auto x: g[u]){
            if(tdis[x.u]<=w+x.w)continue;
            tdis[x.u]=w+x.w;
            if(tdis[x.u]+dis[x.u]==dis[n])mark[x.i]=1;
            h.push({x.u,w+x.w});
        }
    }
    //printf("HERE\n");
    for(i=1;i<=n;i++){
        if(l[i]){
            qs[li[i]]++;
            dfs(li[i],li[i]);
        }
    }
    for(i=1;i<n;i++)printf("%d ",qs[i]);
    return 0;
}
/*
8
2 1 5
3 2 12
4 1 17
5 2 13
6 3 6
7 4 7
8 4 15
*/
