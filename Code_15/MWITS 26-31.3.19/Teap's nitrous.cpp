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
    bool operator < (const A&o) const {
    return w>o.w;
    }
};
vector< A > g[5010];
priority_queue< A > h;
int dis[5010][130];
int main()
{
    int m,n,k,u,v,w,nk,i,j;
    scanf("%d %d %d",&n,&m,&k);
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(i=0;i<=n;i++){
        for(j=0;j<=k;j++){
            dis[i][j]=1<<30;
        }
    }
    dis[1][0]=0;
    h.push({1,0,0});
    while(!h.empty()){
        u=h.top().v,w=h.top().w,nk=h.top().k;
        h.pop();
        if(u==n && nk==0)break;
        for(auto x:g[u]){
            if(nk<k && x.w/2+w<dis[x.v][nk+1]){
                dis[x.v][nk+1]=x.w/2+w;
                h.push({x.v,dis[x.v][nk+1],nk+1});
            }
            if(x.w+w<dis[x.v][nk]){
                dis[x.v][nk]=x.w+w;
                h.push({x.v,dis[x.v][nk],nk});
            }
        }
    }
    int Min=dis[n][0];
    printf("%d\n",dis[n][0]);
    for(i=1;i<=k;i++){
        Min=min(Min,dis[n][i]);
    }
    printf("%d\n",Min);
    printf("%d\n",dis[n][0]-Min);
    return 0;
}
/*
6 8 1
1 2 4
1 4 2
2 3 4
2 4 6
3 6 6
4 3 12
4 5 10
5 6 4
*/
