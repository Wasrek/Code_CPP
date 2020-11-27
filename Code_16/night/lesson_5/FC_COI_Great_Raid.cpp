/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010],p[100010];
long long fin(long long i) {
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
struct A{
    long long u,v,w;
    bool operator <(const A & o) const{
        return w>o.w;
    }
};
priority_queue< A > h;
int main()
{
    long long n,m,u,v,tu,tv;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        p[i]=i;
    }
    scanf("%lld",&m);
    for(int i=1;i<=m;i++){
        scanf("%lld %lld",&u,&v);
        h.push({u,v,(a[u]+a[v])});
    }
    long long sum=0;
    while(!h.empty()){
        tu=h.top().u;
        tv=h.top().v;
        h.pop();
        if(fin(tu)==fin(tv)) continue;
        sum+=a[tu]+a[tv];
        p[fin(tu)]=fin(tv);
    }
    printf("%lld\n",sum);
    return 0;
}
/*
10 
1 2 1 2 3 1 2 1 2 1
15 
5 1
10 8
5 4
7 10
10 9
2 5 
8 4
6 10
7 8
8 5
3 8
6 8
3 1
2 3
3 5
*/