/*
    TASK:Food_Web
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[100005];
int in[100005],lv[100005],dp[22][100005];
void dfs(int u,int level){
    lv[u] = level;
    for(auto x: g[u]){
        dp[0][x]=u;
        dfs(x,level+1);
    }
}
int LCA(int a,int b){
    if(lv[a] < lv[b])swap(a,b);
    //check if b is below b cuz a need to be below b
    for(int i=20;i>=0;i--){
        if(lv[dp[i][a]] >= lv[b]){
            a = dp[i][a];
        }
    }
    if(a==b) return a;
    for(int i=20;i>=0;i--){
        if(dp[i][a] != dp[i][b]){
            a = dp[i][a]; b = dp[i][b];
        }
    }
    return dp[0][a];
}
int main()
{
    int n,i,u,v,root,q,j;
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v),in[v]++;
    }
    for(i=1;i<=n;i++){
        if(in[i]==0){
            root = i;
            break;
        }
    }
    dfs(root,1);//now lvl
    for(i=1;i<20;i++){
        for(j=1;j<=n;j++){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&u,&v);
        printf("%d\n",LCA(u,v));
    }
    return 0;
}
