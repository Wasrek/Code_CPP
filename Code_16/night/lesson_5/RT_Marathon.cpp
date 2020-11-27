/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int p,w;
    bool operator <(const A & o) const{
        return p<o.p;
    }
};
struct B{
    int u,w,d;
};
struct H{
    long long u,w;
    bool operator <(const H & o) const{
        return w>o.w;
    }
};
priority_queue< H > h;
vector< B > g[100010];
A sh[100010];
long long dis[100010];
int main()
{
    int n,m,k,t,p,w,d,u,v;
    scanf("%d %d %d %d",&n,&m,&k,&t);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d %d",&u,&v,&d,&w);
        g[u].push_back({v,w,d});
        g[v].push_back({u,w,d});
    }
    for(int i=1;i<=k;i++){
        scanf("%d %d",&sh[i].w,&sh[i].p);
    }
    sort(sh+1,sh+1+k);
    for(int i=k-1;i>=1;i--){
        sh[i].w=min(sh[i].w,sh[i+1].w);
    }
    int l=0,r=k+1,mid,ch=0;
    while(l<r){
        mid=(l+r)/2;
        for(int i=1;i<=n;i++) dis[i]=1<<30;
        dis[1]=0;ch=0;
        h.push({1,0});
        while(!h.empty()){
            u=h.top().u;
            w=h.top().w;
            h.pop();
            if(u==n){
                if(w<=t) ch=1;
                break;
            }
            // printf("- %d %d\n",u,w);
            for(auto x: g[u]){
                // printf("-- %d %d %d %d\n",x.u,x.w,x.d,sh[mid].p);
                if(dis[x.u]<=w+x.w || x.d>sh[mid].p) continue;
                dis[x.u]=w+x.w;
                h.push({x.u,dis[x.u]});
            }
        }
        while(!h.empty()) h.pop();
        // printf("%d %d\n",mid,ch);
        if(ch) r=mid;
        else l=mid+1;
    }
    // printf("%d\n",l);
    if(l>k) printf("-1\n");
    else printf("%d\n",sh[l].w);
    return 0;
}
/*
2 2 3 50
1 2 50 100
1 2 100 50
40 70
30 50
70 100
*/