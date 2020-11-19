/*
    TASK:Budget Travelling TOI13
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,w;
    bool operator<(const A &o)const {
        if(w!=o.w)
        return w>o.w;
        return i>o.i;
    }
};
priority_queue< A > h;
vector< A > g[10100];
long long len[10100],dis[10100];
int main(){
    long long n,m,u,v,w,s,e,have,ii,ww,i,mi=1<<30,wei,ans;
    scanf("%lld %lld",&n,&m);
    scanf("%lld %lld %lld",&s,&e,&have);
    for(i=0;i<n;i++)dis[i]=len[i]=1<<30;
    while(m--){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
     h.push({e,0});
     len[e]=0;
    while(!h.empty()){
        ii=h.top().i;
        ww=h.top().w;
        h.pop();
        //printf("%d %d\n",ii,len[ii]);
        for(auto x:g[ii]){
            if(len[x.i]<=ww+x.w)continue;
            len[x.i]=ww+x.w;
            h.push({x.i,len[x.i]});
        }
    }
    //for(i=0;i<n;i++)printf("%lld\n",len[i]);
    while(!h.empty())h.pop();
    h.push({s,0});
    while(!h.empty()){
        ii=h.top().i;
        ww=h.top().w;
        h.pop();
        if(ii==e){
            printf("%lld %lld %lld",ii,ww,len[ii]);
            return 0;
        }
//        mi=len[ii];
//            wei=ww;
//            ans=ii;
//        printf("%lld %lld %lld\n",ans,wei,mi);
        if(mi>len[ii] || (ii<ans && mi==len[ii])){
            mi=len[ii];
            wei=ww;
            ans=ii;
            //printf("%lld %lld %lld\n",ans,wei,mi);
        }
        for(auto x:g[ii]){
            if(ww+x.w>have)continue;
            if(dis[x.i]<=ww+x.w)continue;
            dis[x.i]=ww+x.w;
            h.push({x.i,dis[x.i]});
        }
    }
    printf("%lld %lld %lld",ans,wei,mi);
    return 0;
}
/*
8 11
0 5 200
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

8 11
0 5 45
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
