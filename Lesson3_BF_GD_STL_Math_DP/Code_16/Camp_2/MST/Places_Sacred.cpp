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
    bool operator<(const A & o) const{
        return w<o.w;
    }
};
priority_queue< A > h;
int p[200010];
int fin(int i){
    if(p[i]==i) return i;
    else return p[i]=fin(p[i]);
}
int main()
{
    int n,m,u,v,w;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) p[i]=i;
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        w--;
        h.push({u,v,w});
    }
    long long ans=0;
    while(!h.empty()){
        u=h.top().u;
        v=h.top().v;
        w=h.top().w;
        u=fin(u);
        v=fin(v);
        h.pop();
        if(u!=v){
            ans+=w;
            p[u]=v;
        }
    }
    printf("%lld\n",ans);
    return 0;
}