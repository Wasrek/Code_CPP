/*
    TASK:File Transfer
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[1100];
int mark[1100];
void dfs(int now){
   int i;
   for(i=0;i<g[now].size();i++){
    if(mark[g[now][i]]==-1){
        mark[g[now][i]]=1;
        dfs(g[now][i]);
    }
   }
}
int main()
{
    int n,m,q,r,s;
    scanf("%d %d %d",&n,&m,&q);
    while(m--){
        scanf("%d %d",&r,&s);
        g[r].push_back(s);
    }
    while(q--){
        scanf("%d %d",&r,&s);
        memset(mark,-1,sizeof mark);
        mark[r]=1;
        dfs(r);
        if(mark[s]==1) printf("Yes\n");
        else           printf("No\n");
    }
}
