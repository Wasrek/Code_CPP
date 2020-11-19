/*
    TASK:Semicircle
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1001
struct A{
    int s,e;
};
A w[750];
vector< int > g[750];
int color[750];
int dfs(int i,int col){
    if(color[i] && color[i]==col) return 1;
    if(color[i] && color[i]!=col) return 0;
    color[i]=col;
    for(auto x: g[i]){
        if(!dfs(x,3-col)) return 0;
    }
    return 1;
}
int main()
{
    int q,n,cnt,ch;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&w[i].s,&w[i].e);
            for(int j=1;j<i;j++){
                if(w[i].s<w[j].e && w[i].e>w[j].e && w[i].s>w[j].s){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }else if(w[i].s<w[j].s && w[i].e>w[j].s && w[i].e<w[j].e){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     printf("%d ",i);
        //     for(auto x: g[i]){
        //         printf("%d ",x);
        //     }
        //     printf("\n");
        // }
        cnt=0;
        ch=0;
        for(int i=1;i<=n;i++){
            if(!color[i]){
                if(cnt==0)cnt=2;
                else {
                    cnt*=2;
                    cnt%=mod;
                }
                if(!dfs(i,1)){ch=1;break;}
            }
        }
        if(ch){
            printf("0\n");
        }else{
            printf("%d\n",cnt);
        }
        memset(color,0,sizeof color);
        for(int i=1;i<=n;i++) g[i].clear();
    }
    return 0;
}