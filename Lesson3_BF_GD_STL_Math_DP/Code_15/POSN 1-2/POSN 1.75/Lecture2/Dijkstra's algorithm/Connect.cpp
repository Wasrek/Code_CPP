/*
    TASK:Connect Fast
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> PDD;
PDD p[1010];
double dist[1010];
struct A{
    int v;double w;
    bool operator< (const A& o)const{
        return w>o.w;
    }
};
priority_queue<A> dijk;
vector< A > g[1010];
int main()
{
    int n,m,i,u,v,j,nown;
    double maxw,noww;
    scanf("%d %d %lf",&n,&m,&maxw);
    for(i=1;i<=n;i++)
        scanf("%lf %lf",&p[i].first,&p[i].second);
    for(i=1;i<=n;i++){
        dist[i]=1e12;
        for(j=i+1;j<=n;j++){
            noww=sqrt(pow(p[i].first-p[j].first,2)+pow(p[i].second-p[j].second,2));
            if(noww<=maxw){
                g[i].push_back({j,noww});
                g[j].push_back({i,noww});
            }
        }
    }
    while(m--){
        scanf("%d %d",&u,&v);
        g[u].push_back({v,0}),g[v].push_back({u,0});
    }
    for(i=1;i<=n;i++)
        dist[i]=1e12;
    dist[1]=0;
    dijk.push({1,0});
    while(!dijk.empty()){
        nown=dijk.top().v,noww=dijk.top().w;dijk.pop();
        if(nown==n){
            printf("%d\n",(int)(noww*1000));
            return 0;
        }
        for(auto x: g[nown]){
            if(noww+x.w < dist[x.v])
            dist[x.v]=noww+x.w,dijk.push({x.v,dist[x.v]});
        }
    }
    printf("-1\n");
    return 0;
}
/*
9 3
2.0
0 0
0 1
1 1
2 1
2 2
3 2
3 3
4 1
4 3
1 2
2 3
3 4
*/
