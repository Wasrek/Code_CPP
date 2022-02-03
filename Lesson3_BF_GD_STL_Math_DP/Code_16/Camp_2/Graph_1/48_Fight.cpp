/*
    TASK:48_Fight
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,t;
};
vector< A > g[100010];
int color[100010],mid;
int dfs(int i,int col){
    if(color[i] && color[i]==col) return 1;
    if(color[i] && color[i]!=col) return 0;
    color[i]=col;
    for(auto x: g[i]){
        if(x.t>mid)continue;
        if(!dfs(x.v,3-col)) return 0;
    }
    return 1;
}
int main()
{
    int n,m,a,b,ch;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back({b,i});
        g[b].push_back({a,i});
    }
    int l=0,r=m;
    while(l<r){
        mid=(l+r+1)/2;
        ch=0;
        for(int i=1;i<=n;i++){
            if(!color[i]){
                if(!dfs(i,1)){
                    ch=1;
                    break;
                }
            }
        }
        // printf("%d %d\n",mid,ch);
        memset(color,0,sizeof color);
        if(ch)r=mid-1;
        else l=mid;
    }
    printf("%d\n",l+1);
    return 0;
}