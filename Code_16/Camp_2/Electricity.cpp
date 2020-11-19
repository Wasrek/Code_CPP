/*
    TASK:Electricity
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long idx,w;
    bool operator<(const A & o) const{
        if(w!=o.w) return w>o.w;
        else return idx<o.idx;
    }
};
int a[500010];
priority_queue< A >h;
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        while(!h.empty() && h.top().idx+k<i)h.pop();
        if(h.empty()){
            h.push({i,a[i]});
            continue;
        }
        h.push({i,h.top().w+a[i]});
    }
    while(!h.empty() && h.top().idx!=n) h.pop();
    printf("%lld\n",h.top().w);
    return 0;
}