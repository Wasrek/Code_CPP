/*
    TASK:FC_ COI Great Raid
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,v,w;
    bool operator<(const A & o) const{
        return w<o.w;
    }
};
vector< A > v;
long long s[100010],p[100010];
long long fin(long long i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main(){
    long long n,i,k,a,b,w,ans=0,tu,tv,tw;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&s[i]);
        p[i]=i;
    }
    scanf("%lld",&k);
    while(k--){
        scanf("%lld %lld",&a,&b);
        w=s[a]+s[b];
        v.push_back({a,b,w});
    }
    sort(v.begin(),v.end());
    for(i=0;i<v.size();i++){
        tu=v[i].u;
        tv=v[i].v;
        tw=v[i].w;
        tu=fin(tu);
        tv=fin(tv);
        if(tu!=tv){
            p[tv]=tu;
            ans+=tw;
        }
    }
    printf("%lld\n",ans);
}
