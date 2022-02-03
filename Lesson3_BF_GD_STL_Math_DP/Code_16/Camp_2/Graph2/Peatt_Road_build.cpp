/*
    TASK:Peatt Road build
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,w,ma,cnt;
    bool operator<(const A & o) const{
        if(w!=o.w) return w>o.w;
        else return ma>o.ma;
    }
};
priority_queue< A > h;
vector< A > g[1010];
int dis[2][1010];
int main()
{
    int n,m,u,v,w;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w,i});
        g[v].push_back({u,w,i});
    }
    for(int i=1;i<=n;i++){
        dis[0][i]=dis[1][i]=2e9;
    }
    int i,mx,cou;
    dis[1][i]=0;
    h.push({1,0,0,1});
    while(!h.empty()){
        i=h.top().i;
        w=h.top().w;
        mx=h.top().ma;
        cou=h.top().cnt;
        h.pop();
        // printf("%d %d %d %d\n",i,w,mx,cou);
        if(i==n && !cou){
            printf("%d %d\n",mx,w);
            return 0;
        }
        for(auto x: g[i]){
            // printf("%d %d\n",x.i,x.w);
            if(dis[cou^1][x.i]<w+x.w) continue;
            // printf("go\n");
            dis[cou^1][x.i]=w+x.w;
            h.push({x.i,w+x.w,max(mx,x.ma),cou^1});
        }
    }
    return 0;
}