/*
    TASK:
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[22][100007],lv[100007],in[100007];
vector<int> g[100007];
void dfs(int u,int p,int lvl)
{
    dp[0][u]=p;
    lv[u]=lvl;
    for(auto e :g[u])
    {
        dfs(e,u,lvl+1);
    }
}
int LCA(int a,int b)
{
    if(lv[a]<lv[b])
        swap(a,b);
    //a is below b
    int i;
    for(i=20; i>=0; i--)
    {
        if(lv[dp[i][a]] >= lv[b])
            a = dp[i][a];
    }
    if(a==b)
        return a;
    for(i=20; i>=0; i--)
    {
        if(dp[i][a]!=dp[i][b])
            a=dp[i][a],b=dp[i][b];
    }
    return dp[0][a];
}
int main()
{
    int n,i,a,b,root,j,q;
    scanf("%d",&n);
    for(i=1; i<n; i++)
    {
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        in[b]++;
    }
    for(i=1; i<=n; i++)
    {
        if(in[i]==0)
        {
            root=i;
            break;
        }
    }
    dfs(root,0,1);
    for(i=1; i<=20; i++)
    {
        for(j=1; j<=n; j++)
            dp[i][j]=dp[i-1][dp[i-1][j]];
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",LCA(a,b));
    }
}
