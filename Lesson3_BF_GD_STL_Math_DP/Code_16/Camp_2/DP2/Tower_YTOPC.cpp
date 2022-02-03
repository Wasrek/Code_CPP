/*
    TASK:Tower YTOPC
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[10010];
vector< int > g[10010];
int main()
{
    int k,n,m,a,b,ma=0;
    scanf("%d %d %d",&k,&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++) dp[i]=2e9;
    dp[1]=0;
    for(int i=1;i<=n;i++){
        if(dp[i]==2e9) continue;
        ma=i;
        if(dp[i]==k) continue;
        for(auto x: g[i]){
            dp[x]=min(dp[x],dp[i]+1);
        }
    }
    printf("%d\n",ma);
    return 0;
}