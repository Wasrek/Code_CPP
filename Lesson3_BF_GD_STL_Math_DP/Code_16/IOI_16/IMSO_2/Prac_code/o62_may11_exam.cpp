/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define SIZE 100100
int scc[SIZE],lowlink[SIZE],idx[SIZE],onst[SIZE],cnt=0,sccnt=0,in[SIZE],hp[SIZE];
char t[SIZE][35];
vector< int > g[SIZE];
stack<int> st;
void dfs(int i){
    idx[i]=lowlink[i]=++cnt;
    onst[i]=1;
    st.push(i);
    for(auto x: g[i]){
        if(!idx[x]){
            dfs(x);
            lowlink[i]=min(lowlink[i],lowlink[x]);
        }else if(onst[x]){
            lowlink[i]=min(lowlink[i],idx[x]);
        }
    }
    int now;
    if(lowlink[i]==idx[i]){
        sccnt++;
        while(!st.empty()){
            now=st.top();
            scc[now]=sccnt;
            onst[now]=0;
            st.pop();
            if(now==i) break;
        }
    }
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf(" %s",t[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(t[i][j]=='1') g[i].push_back(n+j),hp[n+j]=1;
            else g[n+j].push_back(i);
        }
    }
    for(int i=1;i<=n+k;i++){
        if(!idx[i]) dfs(i);
    }
    for(int i=1;i<=n+k;i++){
        if(i>n && !hp[i]){
            in[scc[i]]++;
            continue;
        }
        for(auto x: g[i]){
            if(scc[i]!=scc[x]) in[scc[x]]++;
        }
    }
    int cnt=0,ans=0;
    for(int i=1;i<=sccnt;i++){
        if(!in[i]){
            cnt++;
            ans=i;
            if(cnt>1) break;
        }
    }
    if(cnt!=1){
        printf("-1\n");
    }else{
        cnt=0;
        for(int i=1;i<=n;i++){
            if(scc[i]==ans){
                printf("%d ",i);
                cnt++;
            }
        }
        if(cnt==0) printf("-1\n");
    }
    return 0;
}