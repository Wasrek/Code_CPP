

#include<bits/stdc++.h>
using namespace std;
vector<long long> a[100100];
long long w[100100],mark[100100],Min,ans,sum;
long long dfs(long long u,long long la){
    long long ans1=w[u];
    for(long long j=0;j<a[u].size();j++)
    {
        if(a[u][j]==la)
            continue ;
        ans1+=dfs(a[u][j],u);
    }
    ans=abs(sum-ans1*2);
    Min=min(Min,ans);
    return ans1;
}
int main(){
    long long q,n,j,x,y,ans2,k,i;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        k=n-1;
        while(k--){
            scanf("%lld %lld",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        sum=0;
        for(i=1;i<=n;i++){
            scanf("%lld",&x);
            w[i]=x;
            sum+=x;
        }
        ans2=0,Min=LONG_LONG_MAX,ans=0;
        dfs(1,0);
        printf("%lld\n",Min);
        for(i=1;i<=n;i++)a[i].clear();
    }
}
/*
2
6
1 2
1 3
1 5
5 6
6 4
2 1 3 3 4 6
*/
