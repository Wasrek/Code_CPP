/*
    TASK:AP_Tree
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector< int > g[100010];
long long w[100010],ans,sumall;
long long dfs(int now,int last){
    long long sum=w[now];
    for(auto x: g[now]){
        if(x!=last){
            sum+=dfs(x,now);
        }
    }
    ans=min(ans,abs(sumall-(sum*2)));
    return sum;
}
int main()
{
    int q,n,a,b;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            scanf("%d %d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        sumall=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&w[i]);
            sumall+=w[i];
        }
        ans=LONG_LONG_MAX;
        dfs(1,0);
        printf("%lld\n",ans);
        for(int i=1;i<=n;i++) g[i].clear();
    }
    return 0;
}