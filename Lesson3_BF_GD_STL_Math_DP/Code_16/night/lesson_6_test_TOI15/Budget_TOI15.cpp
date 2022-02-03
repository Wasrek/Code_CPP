/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator< (const A & o) const{
        return w>o.w;
    }
};
struct B{
    int d,p;
    bool operator <(const B & o) const{
        return d<o.d;
    }
};
B a[300010];
priority_queue< A > h;
int p[3010],bs[300010];
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
vector< int > need;
int main()
{
    int n,m,u,v,w,k,d;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d %d %d %d",&u,&v,&w,&k);
        if(!k){
            h.push({u,v,w});
            // printf("%d %d %d\n",u,v,w);
        }else{
            p[fin(u)]=fin(v);
        }
    }
    // for(int i=1;i<=n;i++) printf("%d ",p[i]);
    // printf("\n");
    while(!h.empty()){
        u=h.top().u;
        v=h.top().v;
        w=h.top().w;
        h.pop();
        u=fin(u);
        v=fin(v);
        if(u==v) continue;
        need.push_back(w);
        // printf("%d ",w);
        p[u]=v;
    }
    // printf("\n");
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        scanf("%d %d",&a[i].d,&a[i].p);
    }
    sort(a+1,a+1+k);
    bs[k]=a[k].d;
    for(int i=k-1;i>=1;i--){
        a[i].p=min(a[i+1].p,a[i].p);
        bs[i]=a[i].d;
    }
    // for(int i=1;i<=k;i++){
    //     printf("%d %d\n",a[i].d,a[i].p);
    // }
    long long ans=0,idx;
    for(auto x: need){
        idx=lower_bound(bs+1,bs+1+k,x)-bs;
        ans+=a[idx].p;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
6 8
0 1 19 0
1 2 50 1
1 3 5 0
2 3 18 0
0 4 32 0
3 4 22 0
2 5 70 0
4 5 20 1
8
5 60
50 200
75 350
20 100
40 145
15 50
35 150
8 60
*/