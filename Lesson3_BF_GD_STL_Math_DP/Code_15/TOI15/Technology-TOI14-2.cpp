/*
    TASK:Technology TOI14
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,id;
    bool operator<(const A&o)const{
        if(id!=o.id)return id>o.id;
        else return i>o.i;
    }
};
int l[100100],mark[100100],dgi[100100],can[100100],dgh[100100],mm[100100],dp[100100],hh[100100];
vector<int> g[100100];
priority_queue<A> h;
stack<int> st;
queue<int>bfs;
void dfs(int u){
    dp[u]=l[u];
    mark[u]=1;
    for(auto x:g[u]){
        if(!mark[x] && can[x])dfs(x);
        if(mark[x])dp[u]=min(dp[u],dp[x]);
    }
}
int main(){
    int n,k,t,i,p,b,u;
    scanf("%d %d %d",&n,&k,&t);
    for(i=1;i<=n;i++){
        scanf("%d %d",&l[i],&p);
        mm[l[i]]++;
        dgi[i]+=p;
        dgh[i]=dgi[i];
        while(p--){
            scanf("%d",&b);
            g[b].push_back(i);
        }
    }
    for(i=1;i<=n;i++){
        if(!dgi[i])bfs.push(i),st.push(i);
    }
    while(!bfs.empty()){
        u=bfs.front();
        bfs.pop();
        can[u]=1;
        for(int x:g[u]){
            dgi[x]--;
            if(!dgi[x])bfs.push(x);
        }
    }
    memset(dp,127,sizeof dp);
    while(!st.empty()){
        if(!mark[st.top()])dfs(st.top());
        st.pop();
    }
    for(i=1;i<=n;i++){
        if(!dgh[i])h.push({i,dp[i]});
    }
    int j=0,ma=-1,cnt=0;
    while(!h.empty()){
        if(j==t)break;
        u=h.top().i;
        h.pop();
        j++;
        hh[l[u]]++;
        for(int x:g[u]){
            dgh[x]--;
            if(!dgh[x])h.push({x,dp[x]});
        }
    }
    ma = 1;
    if(mm[1] != hh[1]){
        printf("-1\n");
        return 0;
    }
    else{
        for(i=2;i<=k;i++){
            if(mm[i] == hh[i])
                ma = i;
            else
                break;
        }
        printf("%d\n",ma);
    }
}
/*
7 4 7
3 1 2
1 0
4 2 7 1
1 1 5
2 1 2
3 1 4
4 1 6
*/
