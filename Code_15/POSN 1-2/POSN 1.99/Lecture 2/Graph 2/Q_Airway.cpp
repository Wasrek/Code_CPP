/*
    TASK:Q_Airway
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w,day;
    bool operator <(const A&o) const{
        return w>o.w;
    }
};
priority_queue<A> dijk;
vector<A> g[1100];
int dis[1100];
int main(){
    int v,e,x,y,a,b,t,i,u,k,w;
    scanf("%d %d %d %d %d %d %d %d",&v,&e,&x,&y,&a,&b,&t,&k);
    g[a].push_back({b,t,k});
    while(e--){
        scanf("%d %d %d",&a,&b,&t);
        g[a].push_back({b,t,0});
    }
    for(i=0;i<=v;i++)dis[i]=1e9;
    dis[x]=0;
    dijk.push({x,0,0});
    while(!dijk.empty()){
        u=dijk.top().v,w=dijk.top().w;dijk.pop();
        if(u==y){
            printf("%d\n",w); return 0;
        }
        for(auto x:g[u]){
            if(x.day!=0 && w<=x.day && dis[u]+x.w < dis[x.v]){
                dis[x.v]=dis[u]+x.w;
                dijk.push({x.v,dis[x.v],0});
            }else if(x.day==0 && dis[u]+x.w<dis[x.v]){
                dis[x.v]=dis[u]+x.w;
                dijk.push({x.v,dis[x.v],0});
            }
        }
    }
    return 0;
}

/*
4 4
0 3
1 3 -10 10
0 1 5
0 3 10
1 3 3
2 3 5
*/
