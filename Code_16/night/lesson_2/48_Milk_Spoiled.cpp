/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,v;
    bool operator<(const A & o) const{
        return i<o.i;
    }
};
vector< A > g;
int main()
{
    long long q,n,x,y,z,a,b,cnt,ma;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld %lld %lld",&n,&x,&y,&z);
        cnt=0;
        for(int i=1;i<=n;i++){
            scanf("%lld %lld",&a,&b);
            g.push_back({a,1});
            g.push_back({b+1,-1});
        }
        g.push_back({0,0});
        sort(g.begin(),g.end());
        ma=0;
        for(int i=0;i<g.size();i++){
            if(g[i].v==1) cnt++;
            if(i) g[i].v+= g[i-1].v;
            if(g[i].i==g[i+1].i) continue;
            ma=max(ma,(cnt-g[i].v)*z + (g[i].v)*y + (n-cnt)*x);
            // printf("%lld %lld %lld\n",g[i].i,g[i].v,ma);
        }
        ma=max(ma,n*z);
        printf("%lld\n",ma);
        g.clear();
    }
    return 0;
}