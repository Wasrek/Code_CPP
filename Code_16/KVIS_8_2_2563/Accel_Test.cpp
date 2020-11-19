/*
    TASK:Accel_test
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
struct B{
    int u,w;
    bool operator < (const B&o) const{
        return w<o.w;
    }
};
B x[100010],y[100010],z[100010];
priority_queue< A > h;
int p[100010];
int fin(int i){
    if(p[i]==i) return i;
    else return p[i]=fin(p[i]);
}
int main()
{
    int n,hu,hv,hw;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&x[i].w,&y[i].w,&z[i].w);
        x[i].u=y[i].u=z[i].u=i;
        p[i]=i;
    }
    sort(x+1,x+1+n);
    sort(y+1,y+1+n);
    sort(z+1,z+1+n);
    for(int i=1;i<n;i++){
        h.push({x[i].u,x[i+1].u,abs(x[i].w-x[i+1].w)});
        h.push({y[i].u,y[i+1].u,abs(y[i].w-y[i+1].w)});
        h.push({z[i].u,z[i+1].u,abs(z[i].w-z[i+1].w)});
    }
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
            // printf("%lld\n",ans);
        }
    }
    printf("%lld\n",ans);
    return 0;
}