#include "jumps.h"
#include<bits/stdc++.h>
#include <vector>
// #include "stub.cpp"
using namespace std;
#define SIZE 200010
struct A{
  int l,r;
} poi[SIZE];
bool sub1=true;
int Q=0,idx=1,now;
void init(int N, std::vector<int> H) {
  for(int i=N-1;i>=0;i--){
    poi[i].l=-1;poi[i].r=N;
    now=i+1;
    while(now<=N-1){
      if(H[now]<H[i]){
        now=poi[now].r;
      }else{
        break;
      }
    }
    poi[i].r=min(N,now);
  }
  for(int i=0;i<N;i++){
    now=i-1;
    while(now>=0){
      // printf("%d %d %d\n",i,now,H[now]);
      if(H[now]<H[i]){
        now=poi[now].l;
      }else{
        break;
      }
    }
    poi[i].l=max((-1),now);
    // printf("%d %d\n",i,poi[i].l);
  }
  // for(int i=0;i<N;i++){
  //   printf("%d %d %d\n",i,poi[i].l,poi[i].r);
  // }
}
int mak[SIZE];
struct BFS{
  int i,dis;
};
queue< BFS > q;
int minimum_jumps(int A, int B, int C, int D) {
  ++Q;
  for(int i=A;i<=B;i++){
    mak[i]=Q;
    q.push({i,0});
  }
  int ans=2e9;
  // printf("%d %d\n",plb,chb);
  while(!q.empty()){
    // printf("%d %d\n",q.front().i,q.front().dis);
    if(q.front().i>=C && q.front().i<=D){
      ans=min(ans,q.front().dis);
      while(!q.empty()) q.pop();
      return ans;
    }
    if(poi[q.front().i].l!=-1 && mak[poi[q.front().i].l]!=Q){
      mak[poi[q.front().i].l]=Q;
      q.push({poi[q.front().i].l,q.front().dis+1});
    }
    if(poi[q.front().i].r!=2e9 && mak[poi[q.front().i].r]!=Q){
      mak[poi[q.front().i].r]=Q;
      q.push({poi[q.front().i].r,q.front().dis+1});
    }
    q.pop();
  }
  // printf("%d\n",ans);
  return (ans==2e9)? -1:ans;
}
/*
9 3
8 1 2 3 6 5 4 7 9
*/
