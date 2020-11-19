/*
    TASK:Q_Spy
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator <(const A& o) const{
        return w>o.w;
    }
};
priority_queue< A > h;
int p[1010];
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
int main()
{
    int n,u,v,w,c;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        p[i]=i;
        for(int j=1;j<=n;j++){
            scanf("%d",&w);
            if(j>i){
                h.push({i,j,w});
            }
        }
    }
    // printf("here");
    for(int i=1;i<=n;i++){
        scanf("%d",&c);
        h.push({i,n+1,c});
    }
    p[n+1]=n+1;
    int hu,hv,hw;
    long long ans=0;
    while(!h.empty()){
        hu=h.top().u;
        hv=h.top().v;
        hw=h.top().w;
        h.pop();
        hu=fin(hu);
        hv=fin(hv);
        if(hu!=hv){
            p[hu]=hv;
            ans+=hw;
        }
    }
    printf("%lld\n",ans);
    return 0;
}