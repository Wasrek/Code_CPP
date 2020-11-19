/*
    TASK:Weak point
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector< int > g[500100];
int in[500100],ma[500100],dp[500100];
queue< int > q;
int main()
{
    int n,m,a,b,now,ans=-1,ansi=2e9,cnt=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
        in[a]++;in[b]++;
    }
    for(int i=1;i<=n;i++){
        if(in[i]==1){
            ma[i]=1;
            q.push(i);
        }
    }
    while(!q.empty()){
        now=q.front();
        q.pop();
        for(auto x: g[now]){
            if(ma[x]) continue;
            in[x]--;
            dp[x]+=dp[now]+1;
            if(in[x]<=1){
                ma[x]=1;
                q.push(x);
            }
        }
    }
    // for(int i=1;i<=n;i++) printf("%d ",ma[i]);
    if(!ma[m]){
        for(int i=1;i<=n;i++){
            if(i==m) continue;
            if(ans<dp[i]){
                ans=dp[i];
                ansi=i;
            }
        }
        printf("%d\n%d\n",ansi,ans);
        return 0;
    }else{
        for(auto x: g[m]){
            q.push(x);
            memset(ma,0,sizeof ma);
            ma[x]=1;
            cnt=0;
            while(!q.empty()){
                now=q.front();
                q.pop();
                cnt++;
                for(auto y:g[now]){
                    if(y==m || ma[y]) continue;
                    ma[y]=1;
                    q.push(y);
                }
            }
            cnt--;
            ans=max(ans,cnt);
            if(cnt==ans) ansi=min(ansi,x);
            while(!q.empty())q.pop();
        }
        printf("%d\n%d\n",ansi,ans);
    }
    return 0;
}
/*
12 1
1 2
1 6
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