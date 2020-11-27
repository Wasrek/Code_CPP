/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],xo[100010],all=0,mi=2e9;
vector< int > g[100010];
void dfs(int i,int la){
    int sum=0,now=a[i];
    for(auto x: g[i]){
        if(x==la) continue;
        dfs(x,i);
        sum+=xo[x];
        now^=xo[x];
    }
    sum+=(all^now);
    mi=min(mi,sum);
    xo[i]=now;
    return ;
}
int main()
{
    int n,x,y;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        all^=a[i];
    }
    for(int i=1;i<n;i++){
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,-1);
    printf("%d\n",mi);
    return 0;
}