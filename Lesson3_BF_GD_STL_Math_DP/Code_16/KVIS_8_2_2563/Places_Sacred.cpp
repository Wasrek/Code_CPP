/*
    TASK:Places Sacred
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator <(const A& o) const{
        return w<o.w;
    }
};
int p[200010];
priority_queue< A > h;
int fin(int i){
    if(p[i]==i) return i;
    else return p[i]=fin(p[i]);
}
int main()
{
    int n,m,u,v,pu,pv,w,dis;
    long long ans=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<=n;i++) p[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        h.push({u,v,w-1});
    }
    while(!h.empty()){
        pu=fin(h.top().u);
        pv=fin(h.top().v);
        dis=h.top().w;
        h.pop();
        if(pu!=pv){
            p[pu]=pv;
            ans+=dis;
        }
    }
    printf("%lld\n",ans);

    return 0;
}