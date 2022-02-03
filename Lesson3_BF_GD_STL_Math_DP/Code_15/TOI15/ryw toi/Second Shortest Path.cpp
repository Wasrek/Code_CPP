/*
    TASK:Second Shortest Path
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> h;
vector<A> g[10100];
int dis[2][10100];
int main(){
    int v,e,s,t,u,w,tv,tw,i,m;
    scanf("%d %d %d %d",&m,&e,&s,&t);
    while(e--){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
    }
    for(i=0;i<=m;i++){
        dis[0][i]=dis[1][i]=1<<30;
    }
    dis[0][s]=0;
    //dis[1][s]=0;
    h.push({s,0});
    while(!h.empty()){
        u=h.top().v;
        tw=h.top().w;
        h.pop();
        for(auto x:g[u]){
            if(x.w+tw<dis[0][x.v]){
                dis[1][x.v]=dis[0][x.v];
                dis[0][x.v]=x.w+tw;
                h.push({x.v,dis[0][x.v]});
            }else if(x.w+tw<dis[1][x.v]){
                dis[1][x.v]=x.w+tw;
                h.push({x.v,dis[1][x.v]});
            }
        }
    }
    printf("%d\n",dis[1][t]);
    return 0;
}
/*
3 3
1 3
1 2 1
1 3 3
2 3 1
*/
