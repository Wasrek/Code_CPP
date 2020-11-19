/*
    TASK:Fast Contest
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int mark[10010],dp[10010],in[10010];
vector< int > g[10010],gt[10010];
queue< int > q,topo;
void dfs(int i){
    mark[i]=1;
    for(auto x: g[i]){
        if(!mark[x]){
            dfs(x);
        }
    }
    q.push(i);
    // printf("%d ",i);
}
int main()
{
    int n,m,a,b,ch=0;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        in[b]++;
        gt[b].push_back(a);
    }
    int now;
    // int now,inf=1;
    // for(int i=1;i<=n;i++){
    //     if(in[i]==0){
    //         topo.push(i);
    //     }
    // }
    // while(!topo.empty()){
    //     now=topo.front();
    //     topo.pop();
    //     if(now==2){
    //         inf=0;
    //         break;
    //     }
    //     for(auto x: g[now]){
    //         in[x]--;
    //         if(in[x]==0)topo.push(x);
    //     }
    // }
    // if(inf){
    //     while(1){}
    //     printf("inf\n");
    //     return 0;
    // }
    for(int i=1;i<=n;i++){
        if(!mark[i]){
            dfs(i);
        }
    }
    // printf("\n");
    dp[2]=1;
    while(!q.empty()){
        now=q.front();
        q.pop();
        for(auto x: gt[now]){
            dp[x]+=dp[now];
            if(dp[x]>1e9) ch=1;
            dp[x]%=1000000000;
        }
    }
    if(ch) printf("%09d\n",dp[1]);
    else printf("%d\n",dp[1]);
    return 0;
}