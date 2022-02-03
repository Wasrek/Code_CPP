/*
    TASK:Earn_Salary
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[100100];
int sum[100100];
void dfs(int u){
   for(auto x: g[u]){
    sum[x]+=sum[u];
    dfs(x);
   }
/*   int i;
   for(i=0;i<g[u].size();i++){
    sum[g[u][i]]+=sum[u];
    dfs(g[u][i]);
   }*/
}
int main()
{
    int n,m,i,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        g[b].push_back(a);
    }
    while(m--){
        scanf("%d %d",&a,&b);
        sum[a]+=b;
    }
    dfs(1);
    for(i=1;i<=n;i++)
        printf("%d\n",sum[i]);
    return 0;
}
