/*
    TASK:Bipartite graph check
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector< int > g[100010];
int color[100010];
int bipar(int i,int col){
    if(color[i] && color[i]!=col) return 0;
    if(color[i] && color[i]==col) return 1;
    color[i]=col;
    for(auto x: g[i]){
        if(!bipar(x,3-col)){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int q,n,m,u,v,ch;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        while(m--){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ch=1;
        for(int i=1;i<=n;i++) color[i]=0;
        for(int i=1;i<=n;i++){
            if(!color[i]){
                ch=bipar(i,1);
                if(!ch) break;
            }
        }
        if(!ch){
            printf("no\n");
        }else printf("yes\n");
        for(int i=1;i<=n;i++) g[i].clear();
    }
    return 0;
}