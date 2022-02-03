/*
    TASK:NC_Superjump
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i;
    double w;
    int ch;
    bool operator<(const A&o)const{
    return w>o.w;
    }
};
struct B{
    int i;
    double w;
};
priority_queue< A >h;
vector<B> g[10010];
double dis[3][10010];
int main(){
    int n,m,u,v,ii,c,i;
    double t,tw;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        dis[1][i]=dis[0][i]=1<<30;
    }
    while(m--){
        scanf("%d %d %lf",&u,&v,&t);
        g[u].push_back({v,t});
        g[v].push_back({u,t});
    }
    dis[0][0]=dis[1][0]=0;
    h.push({0,0,0});
    while(!h.empty()){
        ii=h.top().i;
        tw=h.top().w;
        c=h.top().ch;
        h.pop();
        if(ii==n-1 && c==0){
            printf("%.2f\n",dis[1][n-1]);
            return 0;
        }
        if(c==0){
            for(auto x:g[ii]){
                if(dis[0][x.i]>tw+x.w){
                    dis[0][x.i]=tw+x.w;
                    h.push({x.i,tw+x.w,0});
                }
            }
            for(auto x:g[ii]){
                if(dis[1][x.i]>tw+0.14){
                    dis[1][x.i]=tw+0.14;
                    h.push({x.i,tw+0.14,1});
                }
            }
        }else
        if(c==1){
            for(auto x:g[ii]){
                if(dis[1][x.i]>tw+x.w){
                    dis[1][x.i]=tw+x.w;
                    h.push({x.i,tw+x.w,1});
                }
            }
        }
    }
}
