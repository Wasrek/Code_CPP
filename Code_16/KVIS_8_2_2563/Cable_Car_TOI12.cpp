/*
    TASK:Cable_Car_TOI12
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
    if(p[i]==i) return i;
    else return p[i]=fin(p[i]);
}
int main()
{
    int n,m,u,v,w,s,d,t;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        h.push({u,v,w});
    }
    scanf("%d %d %d",&s,&d,&t);
    for(int i=1;i<=n;i++) p[i]=i;
    int hu,hv,hw;
    while(!h.empty()){
        hu=h.top().u;
        hv=h.top().v;
        hw=h.top().w;
        h.pop();
        hu=fin(hu);
        hv=fin(hv);
        if(hu!=hv){
            p[hu]=hv;
            if(fin(s)==fin(d)){
                // printf("%d\n",hw);
                hw--;
                if(t%hw==0)printf("%d\n",t/hw);
                else printf("%d\n",t/hw+1);
                return 0;
            }
        }
    }
    return 0;
}