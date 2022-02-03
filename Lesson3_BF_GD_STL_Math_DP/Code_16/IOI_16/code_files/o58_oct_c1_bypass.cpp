/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector< int > g[100100];
long long lay[100100][5],n;
long long ans=0;
void dfs(int now,int last){
    long long child=0,mac1=0,mac2=0;
    for(auto x: g[now]){
        if(x==last) continue;
        dfs(x,now);
        //case 1: 2 1
        ans=max(ans,(long long)lay[x][1]*mac1);
        //case 2: 1 2
        ans=max(ans,(long long)lay[x][0]*mac2);
        //case 3: now 3
        ans=max(ans,(long long)((n-lay[x][0])*lay[x][2]));
        child+=lay[x][0];//1 layer from now
        mac1=max(mac1,lay[x][0]);//1 layers from now
        mac2=max(mac2,lay[x][1]);//2 layers from now
    }
    lay[now][0]=child+1;
    lay[now][1]=mac1;
    lay[now][2]=mac2;
    return ;
}
int main()
{
    int u,v;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    printf("%lld\n",ans);
    return 0;
}