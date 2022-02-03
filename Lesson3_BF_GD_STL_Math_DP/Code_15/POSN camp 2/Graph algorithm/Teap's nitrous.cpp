/*
    TASK:Teap's nitrous
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    int v,w,k;
    bool operator<(const A&o) const
    {
        return w>o.w;
    }
};
int dis[5010][105];
vector<A> g[5010];
priority_queue< A > dijk;
int main()
{
    int n,m,k,s,e,w,i,j,v,nk,mi=1e9;
    scanf("%d %d %d",&n,&m,&k);
    while(m--)
    {
        scanf("%d %d %d",&s,&e,&w);
        g[s].push_back({e,w,0}),g[e].push_back({s,w,0});
    }
    for(i=1; i<=n; i++)
        for(j=0; j<=k; j++)
            dis[i][j]=1<<30;
    dijk.push({1,0,0});
    dis[1][0]=0;
    while(!dijk.empty()){
        v=dijk.top().v,w=dijk.top().w,nk=dijk.top().k;
        dijk.pop();
        if(v==n && nk==0) break;
        for(auto x:g[v]){
            if(nk<k && dis[v][nk]+x.w/2<dis[x.v][nk+1]){
                dis[x.v][nk+1]=dis[v][nk]+x.w/2;
                dijk.push({x.v,dis[x.v][nk+1],nk+1});
            }
            if(dis[v][nk]+x.w<dis[x.v][nk]){
                dis[x.v][nk]=dis[v][nk]+x.w;
                dijk.push({x.v,dis[x.v][nk],nk});
            }
        }
    }
    printf("%d\n",dis[n][0]);
    for(i=1;i<=k;i++)
        mi=min(mi,dis[n][i]);
    printf("%d\n%d\n",mi,dis[n][0]-mi);
}
