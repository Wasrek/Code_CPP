/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,w,w1,mk,w2,ik;
    bool operator< (const A & o) const{
        if(mk!=o.mk){
            return mk>o.mk;
        }else if(w2!=o.w2){
            return w2>o.w2;
        }else if(w!=o.w){
            return w>o.w;
        }
        return ik>o.ik;
    }
};
struct B{
    int u,w;
};
vector< B > g[10100];
int dis[10100][2];
priority_queue< A > h;
int main()
{
    int n,m,s,e,k,u,v,w,tu,tw,tk,tw2,tik,tw1;
    scanf("%d %d",&n,&m);
    scanf("%d %d %d",&s,&e,&k);
    s++;e++;
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        u++;v++;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++) dis[i][0]=dis[i][1]=2e9;
    dis[s][0]=0;
    dis[s][1]=0;
    h.push({s,0,0,0,0});
    while(!h.empty()){
        tu=h.top().u;
        tw=h.top().w;
        tw1=h.top().w1;
        tk=h.top().mk;
        tw2=h.top().w2;
        tik=h.top().ik;
        h.pop();
        // printf("-  %d %d %d %d %d %d\n",tu,tw,tw1,tk,tw2,tik);
        if(tu==e){
            if(tk) printf("%d %d %d\n",tik-1,tw1,tw2);
            else printf("%d %d 0\n",e-1,tw);
            return 0;
        }
        for(auto x: g[tu]){
            if(!tk){
                if(dis[x.u][0]<tw+x.w) continue;
                if(tw+x.w<=k){
                    dis[x.u][0]=tw+x.w;
                    // printf("%d %d %d %d %d %d\n",x.u,dis[x.u][0],0,0,0,0);
                    h.push({x.u,dis[x.u][0],0,0,0,0});
                }else{
                    if(dis[x.u][1]<x.w) continue;
                    dis[x.u][1]=x.w;
                    // printf("%d %d %d %d %d %d\n",x.u,0,tw,1,dis[x.u][1],tu);
                    h.push({x.u,0,tw,1,dis[x.u][1],tu});
                }
            }else{
                if(dis[x.u][1]<tw2+x.w) continue;
                dis[x.u][1]=tw2+x.w;
                // printf("%d %d %d %d %d %d\n",x.u,0,tw1,tk,dis[x.u][1],tik);
                h.push({x.u,0,tw1,tk,dis[x.u][1],tik});
            }
        }
    }
    printf("%d",dis[e][1]);
    return 0;
}
/*
8 11
0 5 50
0 1 10
0 2 10
1 3 10
1 5 70
2 3 10
2 4 30
2 6 10
3 5 30
4 5 20
6 7 15
7 5 20
*/
/*
8 11
0 5 40
0 1 10
0 2 10
1 3 10
1 5 70
2 3 10
2 4 30
2 6 10
3 5 30
4 5 20
6 7 15
7 5 20
*/