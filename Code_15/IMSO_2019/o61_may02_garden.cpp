/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[1010];
int c[1010],cnt=0,cc;
struct A{
    int co[12];
};
A col;
void dfs(int i,A ha,int cn){
    if(ha.co[c[i]])return ;
    ha.co[c[i]]++;
    cn++;
    if(cn==cc){cnt++;cnt%=1000003;return ;}
    for(auto x: g[i]){
        if(ha.co[c[x]])continue;
        dfs(x,ha,cn);
    }
    return ;
}
int main()
{
    int n,m,a,b,ans=0;
    scanf("%d %d %d",&n,&m,&cc);
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        cnt=0;
        dfs(i,col,0);
        ans+=cnt;
        ans%=1000003;
    }
    printf("%d\n",ans%1000003);
    return 0;
}
