/*
    TASK:Weak Point TOI12
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dg[500100],dp[500100],mark[500100];
vector<int> g[500100];
queue<int> bfs;
int main(){
    int n,q,i,u,a,b,s;
    scanf("%d %d",&n,&s);
    q=n;
    while(q--){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
        dg[a]++;
        dg[b]++;
    }
    for(i=1;i<=n;i++){
        if(dg[i]==1)bfs.push(i);
        dp[i]=1;
    }
    while(!bfs.empty()){
        u=bfs.front();
        bfs.pop();
        mark[u]=1;
        for(auto e:g[u]){
            if(mark[e])continue;
            dg[e]--;
            dp[e]+=dp[u];
            if(dg[e]==1)bfs.push(e);
        }
    }
    int ans=-1,node;
    if(!mark[s]){
        for(i=1;i<=n;i++){
            if(i!=s && ans<dp[i]-1){
                ans=dp[i]-1;
                node=i;
            }
        }
    }else{
        sort(g[s].begin(),g[s].end());
        for(auto e:g[s]){
            if(dp[s]<dp[e]){
                if(ans<n-dp[s]-1) ans=n-dp[s]-1,node=e;
            }else if(ans<dp[e]-1)ans=dp[e]-1,node=e;
        }
    }
    printf("%d %d\n",node,ans);
}
