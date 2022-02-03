/*
    TASK:Turbo Programming
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
    bool operator< (const A& o) const{
        return w > o.w;
    }
};
priority_queue<A>dijk;
vector<A> g[1010];
int dist[1010],mark[1010];
int main()
{
    int n,m,q,u,v,w,nown,noww,i;
    scanf("%d %d %d",&n,&m,&q);
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
    }
    for(i=1;i<=n;i++)
        dist[i]=1<<30;
    dist[1]=0;
    dijk.push({1,0});
    while(!dijk.empty())
    {
        nown=dijk.top().v,noww=dijk.top().w;
        dijk.pop();
        mark[nown]=1;
        for(auto x: g[nown]){
            if(!mark[x.v] && dist[nown]+x.w<dist[x.v]){
                dist[x.v] = dist[nown]+x.w;
                dijk.push({x.v,dist[x.v]});
            }
        }
    }
    while(q--){
        scanf("%d",&i);
        if(dist[i]==1<<30) printf("-1\n");
        else printf("%d\n",dist[i]);
    }
    return 0;
}
/*
6 5 3
1 2 10
2 3 10
3 4 10
4 5 10
1 5 50
6
5
4
*/
