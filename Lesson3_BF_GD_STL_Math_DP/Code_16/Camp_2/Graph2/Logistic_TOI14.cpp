/*
    TASK:Logistic TOI14
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,w,ha,u;
    bool operator <(const A & o) const{
        if(w!=o.w) return w>o.w;
        return ha<o.ha;
    }
};
priority_queue< A > h;
int p[110],dis[2][110][110];
vector< A > g[110];
int main()
{
    int n,st,en,f,m,u,v,w;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
        for(int j=0;j<=100;j++){
        dis[1][i][j]=dis[0][i][j]=2e9;
        }
    }
    scanf("%d %d %d",&st,&en,&f);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dis[0][st][0]=0;
    h.push({st,0,0,0});
    int i,ha;
    while(!h.empty()){ 
        i=h.top().i;
        w=h.top().w;
        ha=h.top().ha;
        u=h.top().u;
        h.pop();
        // printf("%d %d %d %d\n",i,w,ha,u);
        if(i==en && ha==f){
            printf("%d\n",dis[1][en][f]);
            return 0;
        }
        if(!u && dis[1][i][f]>w){
            dis[1][i][f]=w;
            h.push({i,w,f,1});
        }
        if(ha<f && dis[u][i][ha+1]>w+p[i]){
            dis[u][i][ha+1]=w+p[i];
            h.push({i,w+p[i],ha+1,u});
        }
        for(auto x: g[i]){
            if(ha>=x.w && dis[u][x.i][ha-x.w]>w){
                dis[u][x.i][ha-x.w]=w;
                h.push({x.i,w,ha-x.w,u});
            }
        }
    }
    return 0;
}