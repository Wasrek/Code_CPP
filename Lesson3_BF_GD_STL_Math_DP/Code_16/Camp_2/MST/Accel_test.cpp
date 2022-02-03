/*
    TASK:Accel test
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,v;
    bool operator <(const A & o) const{
        return v<o.v;
    }
};
struct B{
    int u,v,w;
    bool operator<(const B & o) const{
        return w>o.w;
    }
};
priority_queue< B > h;
A x[100100],y[100100],z[100100];
int p[100100];
int fin(int i){
    if(p[i]==i) return i;
    else return p[i]=fin(p[i]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        p[i]=i;
        x[i].i=y[i].i=z[i].i=i;
        scanf("%d %d %d",&x[i].v,&y[i].v,&z[i].v);
    }
    sort(x+1,x+1+n);
    sort(y+1,y+1+n);
    sort(z+1,z+1+n);
    for(int i=1;i<n;i++){
        h.push({x[i].i,x[i+1].i,x[i+1].v-x[i].v});
        h.push({y[i].i,y[i+1].i,y[i+1].v-y[i].v});
        h.push({z[i].i,z[i+1].i,z[i+1].v-z[i].v});
    }
    int u,v,w;
    long long ans=0;
    while(!h.empty()){
        u=h.top().u;
        v=h.top().v;
        w=h.top().w;
        h.pop();
        u=fin(u);
        v=fin(v);
        if(u!=v){
            ans+=w;
            p[u]=v;
        }
    }
    printf("%lld\n",ans);
    return 0;
}