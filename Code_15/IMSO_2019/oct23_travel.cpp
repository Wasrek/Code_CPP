/*
    TASK:oct23_travel
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[30010][20],lvl[30010];
vector< int> g[30010];
void dfs(int i,int lv,int p){
    lvl[i]=lv;
    dp[i][0]=p;
    for(auto x: g[i]){
        if(x!=p)
        dfs(x,lv+1,i);
    }
    return ;
}
int lca(int a,int b){
    int sum=0;
    if(lvl[a]<lvl[b])swap(a,b);
    for(int i=16;i>=0;i--){
        if(lvl[dp[a][i]]>lvl[b]){
            a=dp[a][i];
            sum+=(1<<i);
        }
    }
    if(lvl[a]!=lvl[b]){
        a=dp[a][0];
        sum++;
    }
    if(a!=b){
        for(int i=16;i>=0;i--){
            if(dp[a][i]!=dp[b][i]){
                a=dp[a][i];
                b=dp[b][i];
                sum+=(1<<(i+1));
            }
        }
        sum+=2;
    }
    return sum;
}
int main()
{
    int n,m,a,b,now,last=1;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,1,0);
    for(int i=1;i<=16;i++){
        for(int j=1;j<=n;j++){
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
    scanf("%d",&m);
    int ans=0;
    for(int i=1;i<=m;i++){
        scanf("%d",&now);
        ans+=lca(now,last);
        // cout << lca(now,last) << endl;
        last=now;
    }
    printf("%d\n",ans);
    return 0;
}
