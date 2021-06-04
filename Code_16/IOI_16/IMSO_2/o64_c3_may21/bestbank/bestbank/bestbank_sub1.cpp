#include "bestbank.h"
#include <vector>
#include<bits/stdc++.h>
using namespace std;
// #include "grader.cpp"
#define SIZE 1010
struct A{
  long long u,w;
};
vector< A > g[SIZE],bank[SIZE];
int pa[20][SIZE],dep[SIZE],n;
long long dis[SIZE];
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

void initialize(int N, int K,std::vector<std::vector<int> > R,std::vector<std::vector<long long> > B)
{
    n=N;
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
    for(int i=0;i<K;i++){
        bank[B[i][0]].push_back({B[i][1],B[i][2]});
    }
}

void update_bank(int P, int F,long long L)
{
  bank[P].push_back({F,L});
}

long long find_best_bank(int S, int Y)
{
    long long mi=1e18;
    for(int i=0;i<n;i++){
        for(auto x: bank[i]){
            mi=min(mi,(x.u*Y)/100+x.w+fin_dis(S,i));
        }
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