/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long p[100100];
long long fin(long long i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
struct A{
    long long u,v,w,i;
    bool operator<(const A & o) const{
        return w<o.w;
    }
};
priority_queue< A > h;
vector< long long > g;
int main()
{
    long long n,m,u,v,w,cnt,t,ch=0,ans=0;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        h.push({u,v,w,i});
    }
    cnt=n;
    scanf("%lld",&t);
    while(!h.empty()){
        u=h.top().u;
        v=h.top().v;
        if(fin(u) !=fin(v)){
            cnt--;
            p[fin(u)]=fin(v);
            ans+=h.top().w;
            g.push_back(h.top().i);
            // printf("%lld\n",h.top().w);
        }else if(!ch){
            cnt--;
            ch=1;
            ans+=h.top().w;
            g.push_back(h.top().i);
            // printf("%lld\n",h.top().w);
        }
        h.pop();
    }
    // printf("%lld\n",cnt);
    if(cnt!=0){
        printf("-1\n");
        return 0;
    }else printf("%lld\n",ans);
    if(t==2){
        for(auto x: g) printf("%lld ",x);
    }
    return 0;
}