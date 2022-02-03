/*
    TASK:RC_PeattaeP
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,b;
};
int ap[100010],br[200020];
int idx[100010],lowlink[100010],cnt=1,root=0;
vector< A > g[100100];
void dfs(int u,int p){
    idx[u]=lowlink[u]=cnt++;
    for(auto x:g[u]){
        if(x.a==p)continue;
        if(idx[x.a]==0){
            if(u==0)root++;
            dfs(x.a,u);
            lowlink[u]=min(lowlink[u],lowlink[x.a]);
            if(lowlink[x.a]>=idx[u] && u!=0)ap[u]=1;
            if(lowlink[x.a]>idx[u])br[x.b]=1;
        }else{
            lowlink[u]=min(lowlink[u],idx[x.a]);
        }

    }
}
int main(){
    int n,m,a,b,i;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back({b,i});
        g[b].push_back({a,i});
   }
   dfs(0,0);
   if(root>=2)ap[0]=1;
   int ans=0;
   for(i=0;i<n;i++){
    if(ap[i])printf("%d ",i),++ans;
   }
   if(!ans) printf("-1");
   ans=0;
   printf("\n");
   for(i=0;i<m;i++){
    if(br[i])printf("%d ",i),ans++;
   }
   if(!ans) printf("-1");
   printf("\n");
   return 0;
}
/*
3
3
0 1 1 2 2 0
*/
