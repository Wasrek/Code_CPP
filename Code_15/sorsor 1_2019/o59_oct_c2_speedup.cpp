/*
    TASK:speedup
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,w;
};
struct B{
    long long u,w,k,l;
    bool operator<(const B&o)const{
        return w>o.w;
    }
};
priority_queue< B > h;
vector< A > g[80010];
long long mark[80010][10],p[80010], vis[80010][10];
int main(){
    long long n,m,l,q,i,j,a,b,w,tu,tw,tk,tl;
    scanf("%lld %lld %lld %lld",&n,&m,&l,&q);
    for(i=1;i<=m;i++){
        scanf("%lld %lld %lld",&a,&b,&w);
        g[a].push_back({b,w});
    }
    for(i=1;i<=l;i++){
        scanf("%lld",&a);
        p[a]=1;
    }
    for(i=1;i<=n;i++){
        for(j=0;j<=q;j++){
            mark[i][j]=1e18;
        }
    }
    mark[1][0]=0;
    h.push({1,0,0,-1});
    while(!h.empty()){
        tu=h.top().u;
        tw=h.top().w;
        tk=h.top().k;
        tl=h.top().l;
        h.pop();
//        if (vis[tu][tk]) continue;
//        vis[tu][tk] = 1;

        if(tu==n){
            printf("%lld\n",tw);
            return 0;
        }


        for(auto x: g[tu]){
            if(tl!=tu && p[tu] && tk+1<=q){
              if(mark[x.u][tk+1] > (x.w>>(tk+1)) + tw){
                mark[x.u][tk+1] = (x.w>>(tk+1)) + tw;
                h.push({x.u, mark[x.u][tk+1], tk+1, tu});
              }
            }
            if(mark[x.u][tk] > (x.w>>tk)+tw){
                    mark[x.u][tk] = (x.w>>tk)+tw;
                    h.push({x.u,(x.w>>tk)+tw,tk,tl});
            }
        }
    }
}
/*
9 9 1 1
1 2 256
2 3 256
3 4 256
4 9 256
1 5 256
5 6 256
6 7 256
7 8 256
8 9 256
5
*/