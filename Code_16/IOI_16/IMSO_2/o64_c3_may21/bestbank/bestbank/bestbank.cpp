#include "bestbank.h"
#include <vector>
#include<bits/stdc++.h>
using namespace std;
#include "grader.cpp"
#define SIZE 100010
struct A{
  int u,w;
};
vector< A > g[SIZE];
int pa[20][SIZE],dep[SIZE],nn=0,sz[SIZE],par[SIZE],mar[SIZE],p_run=0,markk[SIZE][1010];
unordered_map< int,int > mp,re;
long long dis[SIZE],ct[SIZE][1010];
void dfs(int i,int p){
  pa[0][i]=p;
  dep[i]=(i==0) ? 0:dep[p]+1;
  for(auto x:g[i]){
    if(x.u==p) continue;
    dis[x.u]=x.w+dis[i];
    dfs(x.u,i);
  }
}
int nor_lca(int u,int v){
  if(dep[u]<dep[v]) swap(u,v);
  int diff=dep[u]-dep[v];
  for(int i=0;i<=19;i++){
    if(diff>>i & 1) u=pa[i][u];
  }
  if(u==v) return u;
  for(int i=19;i>=0;i--){
    if(pa[i][u]!=pa[i][v]){
      u=pa[i][u],v=pa[i][v];
    }
  }
  return pa[0][u];
}
long long fin_dis(int u,int v){
  int lca=nor_lca(u,v);
  // printf("lca %d %d %d\n",u,v,lca);
  return dis[u]+dis[v]-dis[lca]*2;
}

void sub_dfs(int u, int p){
    if(mar[u]) return;
    nn++;
    sz[u]= 1;
    for(auto x: g[u]){
        if(x.u==p || mar[x.u]) continue;
        sub_dfs(x.u,u);
        sz[u]+= sz[x.u];
    }
}

int getCentroid(int u, int p){
    for(auto x: g[u]){
        if(x.u==p || mar[x.u]) continue;
        if(sz[x.u]>nn/2)
            return getCentroid(x.u, u);
    }
    return u;
}

void decompose(int u, int p){
    nn= 0;
    sub_dfs(u,-1);
    int centroid= getCentroid(u,-1);
    par[centroid]= p;
    mar[centroid]=1;
    for(auto x: g[centroid]){
        if(x.u==p || mar[x.u]) continue;
        decompose(x.u,centroid);
    }
}

void upd_cen(int u,int per,long long a){
  if(!mp[per]){
    mp[per]=++p_run;
    re[p_run]=per;
  }
  int x=u;
  per=mp[per];
  // printf("%d %d %lld\n",u,per,a);
  while(x!=-1){
    // printf("%d %d %d\n",x,ct[x][per],u);
    if(!markk[x][per]){
      ct[x][per]=a+fin_dis(u,x);
      markk[x][per]=1;
    } else ct[x][per]=min(ct[x][per],a+fin_dis(u,x));
    x=par[x];
  }
  return ;
}

void initialize(int N, int K,std::vector<std::vector<int> > R,std::vector<std::vector<long long> > B)
{
  for(int i=0;i<(N-1);i++){
    // printf("%d %d %d\n",R[i][0],R[i][1],R[i][2]);
    g[R[i][0]].push_back({R[i][1],R[i][2]});
    g[R[i][1]].push_back({R[i][0],R[i][2]});
  }
  dfs(0,-1);
  for(int i=1;i<=19;i++){
    for(int j=0;j<N;j++){
      if(pa[i-1][j]!=-1) pa[i][j]=pa[i-1][pa[i-1][j]];
    }
  }
  decompose(0,-1);
  //upd centroid
  for(int i=0;i<K;i++){
    // printf("%d %d %d\n",B[i][0],B[i][1],B[i][2]);
    upd_cen(B[i][0],B[i][1],B[i][2]);
  }
  // for(int i=0;i<N;i++){
  //   printf("%d %d\n",i,dis[i]);
  // }
  // for(int i=0;i<N;i++){
  //   for(int j=0;j<=100;j++){
  //     if(ct[i][j]!=2e9) printf("%d %d %d\n",i,j,ct[i][j]);
  //   }
  // }
}

void update_bank(int P, int F,long long L)
{
  upd_cen(P,F,L);
}

long long find_best_bank(int S, int Y)
{
  // printf("%d %d\n",S,Y);
  int x=S;
  long long mi=1e18,dist;
  while(x!=-1){
    dist=fin_dis(S,x);
    for(int i=1;i<=p_run;i++){
      if(markk[x][i] && dist+((Y*re[i])/100)+ct[x][i]<mi){
        mi=dist+((Y*re[i])/100)+ct[x][i];
        // printf("%d %d %d %d\n",x,i,fin_dis(Y,x),ct[x][i]);
      }
    }
    x=par[x];
  }
  return mi;
}
/*
5 2 4
0 2 15
1 2 6
2 3 5
3 4 7
1 5 3
4 2 5
2 2 100
1 0 1 10
2 2 1000
2 3 500
*/