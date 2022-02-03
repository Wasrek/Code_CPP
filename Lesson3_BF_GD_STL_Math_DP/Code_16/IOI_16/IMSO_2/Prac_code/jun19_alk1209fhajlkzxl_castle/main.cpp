#include <iostream>
#include <vector>
#include "castle.h"
// #include "castle.cpp"

using namespace std;

struct V{
  int i,n;
};

int N,M,Q,Y,tu,tv,ans,cnt=0,idx=0;
vector<int> A,B;

vector< V > g[100100];
int ch[100100],dep[100100],rv[100100],ma[100100];
V p[100100];

void dfs(int u,int la,int lap){
  p[u]={la,lap};
  dep[u]= (la==-1) ? 1:dep[la]+1;
  for(auto x: g[u]){
    if(x.i==la) continue;
    if(dep[x.i]){
      rv[u]=1; continue;
    }
    dfs(x.i,u,x.n);
    if(rv[x.i]) rv[u]=1;
  }
}

int go_top(int u){
  int mi=u,now=u;
  // printf("- %d\n",u);
  ma[u]=idx;
  if(p[u].i!=-1 && !ch[p[u].n] && ma[p[u].i]!=idx)now=go_top(p[u].i);
  if((dep[now]==dep[mi] && now<mi) || (dep[now]<dep[mi])) mi=now;
  for(auto x: g[u]){
    if(ch[x.n] || !rv[x.i] || ma[x.i]==idx || x.i==-1) continue;
    now=go_top(x.i);
    if((dep[now]==dep[mi] && now<mi) || (dep[now]<dep[mi])) mi=now;
  }
  return mi;
}

int main() {
  castle_init(N,M,Q,Y);
  castle_read_map(A,B);
  for(int i=0;i<M;i++){
    g[A[i]].push_back({B[i],i});
    g[B[i]].push_back({A[i],i});
  }
  dfs(0,-1,-1);
  while (Q--) {
    int T,X,Y;
    castle_read_event(T,X,Y);
    if(T==1){
      ch[X]=1;
    }else{
      tu=X,tv=Y;
      ++idx;
      tu=go_top(tu);
      // printf("\n");
      ++idx;
      tv=go_top(tv);
      if(tu==tv) ans=1;
      else ans=0;
        // printf("%d %d\n",tu,tv);
        // printf("%d\n",ans);
    }
    if (T == 2) {
      castle_answer(ans);
    }
  }

}
/*
3 3 6 13
0 1
0 2
1 2
2 1 1
1 1 0
2 2 0
1 2 0
2 2 0
2 1 0
*/