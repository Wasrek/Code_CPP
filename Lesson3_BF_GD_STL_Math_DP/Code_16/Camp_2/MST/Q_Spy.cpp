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
priority_queue< A> h;
int p[1010];
int fin(int i){
    if(p[i]==i) return i;
    else return p[i]=fin(p[i]);
}
int main()
{
    int n,now;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        p[i]=i;
        for(int j=1;j<=n;j++){
            scanf("%d",&now);
            if(j<i){
                h.push({i,j,now});
            }
        }
    }
    p[n+1]=n+1;
    for(int i=1;i<=n;i++){
        scanf("%d",&now);
        h.push({i,n+1,now});
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