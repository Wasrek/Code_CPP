/*
    TASK:RT_Teleport2
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct B{
    long long u,w,a;
    bool operator<(const B&o)const{
    return w>o.w;
    }
};
vector<B> g[10110];
long long dis[21][10010];
priority_queue< B > h;
int main(){
    int n,m,k,a,i,j,u,v,w,d,di;
    scanf("%d %d %d %d",&n,&m,&k,&a);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w,1});
        g[v].push_back({u,w,1});
    }
    for(i=1;i<=k;i++){
        scanf("%d",&d);
        while(d--){
            scanf("%d",&di);
            g[di].push_back({i+n,0,0});
            g[i+n].push_back({di,0,1});
        }
    }
    for(i=1;i<=n+k;i++){
        for(j=0;j<=a;j++){
            dis[j][i]=1<<30;
        }
    }
    h.push({1,0,a});
    dis[a][1]=0;
    long long tu,tw,ta;
    while(!h.empty()){
        tu=h.top().u;
        tw=h.top().w;
        ta=h.top().a;
        h.pop();
        //printf("%lld %lld %lld\n",tu,tw,ta);
        if(tu==n){printf("%lld\n",tw);return 0;}
        for(auto x: g[tu]){
            if(x.a){
            if(dis[ta][x.u]<=x.w+tw)continue;
            //if(ta+1<=a && dis[ta+1][x.u<=x.w+tw])continue;
            dis[ta][x.u]=x.w+tw;
            //printf("--- %d %d\n",x.u,dis[ta][x.u]);
            h.push({x.u,dis[ta][x.u],ta});
            }else{
                if(ta){
                //if(tu==x.u)continue;
                if(dis[ta-1][x.u] <= tw)continue;
                dis[ta-1][x.u]=tw;
                h.push({x.u,tw,ta-1});
                }
            }
        }
    }
//    long long ans=1<<30;
//    for(i=0;i<=a;i++){
//        ans=min(ans,dis[i][n]);
//        printf("%d\n",dis[i][n]);
//    }
//    if(ans>=1e9)
    printf("-1\n");
//    else printf("%lld\n",ans);
}
/*
5 10 2 1
5 1 11
5 4 9
5 4 13
4 5 1
3 4 14
5 4 12
3 5 4
3 5 12
5 1 10
1 5 13
2 1 5
1 3
*/
/*
5 10 2 1
3 4 12
1 5 15
4 2 14
4 2 8
3 3 9
1 2 12
5 3 4
1 1 13
2 3 3
1 3 6
2 2 2
1 1
*/
