/*
    TASK:Minimization
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[300010],mark[300010];
struct A{
    int a,b,w;
    bool operator<(const A &o) const {
        return w>o.w;
    }
};
priority_queue< A > h;
int main()
{
    int n,k,m,ans=0;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    m=n-k;
    sort(a+1,a+1+n);
    for(int i=1;i<=m;i++){
        h.push({i,i+1,-1*abs(a[i+1]-a[i])});
    }
    while(!h.empty() && m>0){
        if(!mark[h.top().a] && !mark[h.top().b]){
        ans+=h.top().w*-1;
        m--;
        mark[h.top().a]++;
        mark[h.top().b]++;
        }
        h.pop();
    }
    printf("%d\n",ans);
    return 0;
}
