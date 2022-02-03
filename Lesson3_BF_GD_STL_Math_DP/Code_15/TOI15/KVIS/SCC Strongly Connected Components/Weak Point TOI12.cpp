/*
    TASK:Weak Point TOI12
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define SIZE 500100
vector<int> g[SIZE];
int dg[SIZE],dp[SIZE],mark[SIZE],mm[SIZE];
queue<int>q;
int main(){
    int n,s,i,a,b,u;
    scanf("%d %d",&n,&s);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
        dg[a]++;
        dg[b]++;
    }
    for(i=1;i<=n;i++){
        if(dg[i]==1){
            q.push(i),mark[i]=1;
        }
    }
    while(!q.empty()){
        u=q.front();
        q.pop();
//        printf("%d\n",u);
        for(auto x: g[u]){
            if(mark[x])continue;
            dp[x]+=dp[u]+1;
            --dg[x];
            if(dg[x]==1)q.push(x),mark[x]=1;
        }
    }
    while(!q.empty()){
        q.pop();
    }
    int ans=-1,node,now;
    if(!mark[s]){
        for(i=1;i<=n;i++){
            if(i!=s && ans<dp[i]){
                ans=dp[i];
                node=i;
            }
        }
    }else{
        sort(g[s].begin(),g[s].end());
        for(auto x:g[s]){
            q.push(x);
            now=0;
            mm[x]=1;
            while(!q.empty()){
                u=q.front();
                q.pop();
                now++;
                for(auto y:g[u]){
                    if(y==s)continue;
                    if(mm[y])continue;
                    q.push(y);
                    mm[y]=1;
                }
            }
            if(now-1>ans){
                ans=now-1;
                node=x;
            }
            while(!q.empty())q.pop();
            memset(mm,0,sizeof mm);
        }
    }
    printf("%d\n%d",node,ans);
}
/*
12 1
1 2 1 6
1 7
1 12
6 8
6 9
2 3
2 10
10 11
3 4
4 5
5 12
*/
