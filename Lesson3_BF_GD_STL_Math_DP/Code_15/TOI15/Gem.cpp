/*
    TASK:Gem
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[400100],gt[400100];
stack<int>st;
int mark[400100],mark2[400100],cnt;
void dfs(int u){
    if(mark[u])return ;
    mark[u]=1;
    for(auto x:g[u])
        dfs(x);
    st.push(u);
}
void dfs2(int u){
    if(mark2[u])return ;
    mark2[u]=cnt;
    for(auto x:gt[u])
        dfs2(x);
}
int main(){
    int q=5,n,m,i,x,y,ch;
    while(q--){
        cnt=1,ch=1;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%d %d",&x,&y);
            g[x*2+1].push_back(y*2);
            g[y*2+1].push_back(x*2);
            gt[y*2].push_back(x*2+1);
            gt[x*2].push_back(y*2+1);
        }
        for(i=0;i<m/2;i++){
            scanf("%d %d",&x,&y);
            g[y*2].push_back(x*2+1);
            g[x*2].push_back(y*2+1);
            gt[x*2+1].push_back(y*2);
            gt[y*2+1].push_back(x*2);
        }
        for(i=2;i<=2*m+1;i++){
            if(!mark[i])
                dfs(i);
        }

        while(!st.empty()){
            if(!mark2[st.top()]){
                dfs2(st.top());
                cnt++;
            }
            st.pop();
        }
        for(i=1;i<=m;i++){
            if(mark2[2*i]==mark2[2*i+1])
                ch=0;
        }
        printf((ch)?"Y\n":"N\n");
        memset(mark,0,sizeof mark);
        memset(mark2,0,sizeof mark2);
        for(i=2;i<=2*m+1;i++){
            g[i].clear();gt[i].clear();
        }
    }
}
