/*
    TASK:48_Fight
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
vector<PII> g[100100];
int color[100100],mid;
int dfs(int u,int col){
    if(color[u]!=0 && color[u]==col) return 1;
    if(color[u]!=0 && color[u]!=col) return 0;
    color[u]=col;
    for(int i=0;i<(int)g[u].size();i++){
        if(g[u][i].second > mid) continue;
        if(dfs(g[u][i].first,3-col)==0)
            return 0;
    }
    return 1;
}
int main()
{
    int n,m,l,r,ch,i,u,v;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back({v,i}),g[v].push_back({u,i});
    }
    l=1,r=m;
    while(l<r){
        mid=(l+r)/2;
        memset(color,0,sizeof color);
        for(i=1,ch=1;i<=n;i++){
            if(!color[i]){
                if(dfs(i,1)==0){
                    ch=0;break;
                }
            }
        }
        if(ch) l=mid+1;
        else r=mid;
    }
    printf("%d\n",l);
    return  0;
}
