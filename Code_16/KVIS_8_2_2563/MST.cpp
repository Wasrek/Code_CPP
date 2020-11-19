/*
    TASK:MST
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
    double w;
    bool operator <(const A& o) const{
        return w>o.w;
    }
};
int p[1010];
priority_queue< A > h;
int fin(int i){
    if(p[i]==i) return i;
    else return p[i]=fin(p[i]);
}
int main()
{
    int n,m,u,v,pu,pv;
    double ans=0,w,dis;
    scanf("%d %d",&n,&m);
    for(int i=0;i<=n;i++) p[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d %d %lf",&u,&v,&w);
        h.push({u,v,w});
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
    printf("%.3f\n",ans);

    return 0;
}