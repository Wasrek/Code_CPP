/*
    TASK:Cable Car TOI12
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
int p[3000];
int fin(int i){
    if(p[i]==i) return p[i];
    else return p[i]=fin(p[i]);
}
int main()
{
    int n,m,s,e,pe,u,v,w;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) p[i]=i;
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        h.push({u,v,w});
    }
    scanf("%d %d %d",&s,&e,&pe);
    while(!h.empty()){
        u=h.top().u;
        v=h.top().v;
        w=h.top().w;
        h.pop();
        u=fin(u);
        v=fin(v);
        if(u!=v){
            p[u]=v;
        }
        s=fin(s);
        e=fin(e);
        if(s==e){
            w--;
            pe=ceil((double)pe/(double)w);
            printf("%d\n",pe);
            return 0;
        }
    }
    return 0;
}