#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,w;
};
vector<A>g[100010];
int in[100010],qs[100010],p[23][100010],lvl[100010];
void dfs(int n,int l){
    for(auto x:g[n]){
        if(x.i == l)    continue;
        qs[x.i] = qs[n]+x.w;
        p[0][x.i] = n;
        lvl[x.i] = lvl[n]+1;
        dfs(x.i,n);
    }
    return ;
}
int LCA(int a,int b){
    if(lvl[a]<lvl[b])   swap(a,b);
    int i;
    for(i=20;i>=0;i--){
        if(lvl[p[i][a]]>=lvl[b]){
            a = p[i][a];
        }
    }
    if(a == b)  return a;
    for(i=20;i>=0;i--){
        if(p[i][a]!=p[i][b])
            a = p[i][a],b = p[i][b];
    }
    return p[0][a];
}
int main(){
    int n,k,i,a,b,w,r = 1,x,y,ans,j;
    scanf("%d %d",&n,&k);
    for(i=1;i<n;i++){
        scanf("%d %d %d",&a,&b,&w);
        a++,b++;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
        in[a]++,in[b]++;
    }
    qs[r] = 0;
    lvl[r] = 1;
    dfs(r,0);
    for(i=1;i<=20;i++){
        for(j=1;j<=n;j++){
            p[i][j] = p[i-1][p[i-1][j]];
        }
    }
    while(k--){
        scanf("%d %d",&x,&y);
        x++;y++;
        ans = qs[x]+qs[y]-(2*qs[LCA(x,y)]);
        printf("%d\n",ans);
    }
}
/*
5 4
0 1 5
0 2 5
1 3 3
1 4 3
*/
