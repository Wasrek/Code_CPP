#include<bits/stdc++.h>
#include "swap.h"
// #include"grader.cpp"
#include <vector>
#define SIZE 100010
#define MAX 2000000000
using namespace std;
struct A{
  int u,w;
  bool operator<(const A & o) const{
    return w<o.w;
  }
};
int n,sub2=1,sub1=1,cycle=1,ma=0,dis[3][3][SIZE];
A m1={MAX,MAX},m2={MAX,MAX},m3={MAX,MAX};
vector<A> g[SIZE];
struct DIJK{
  int u,w,la,ch;
  // nx node from x,ny node from y,mi min node path that between
  bool operator <(const DIJK & o) const{
    if(w!=o.w) return w>o.w;
    //w==o.w
    return ch<o.ch;
  }
} now;
priority_queue< DIJK > h;
void init(int N, int M, std::vector<int> U, std::vector<int> V, std::vector<int> W) {
    n=N;
    for(int i=0;i<M;i++){
      g[U[i]].push_back({V[i],W[i]});
      g[V[i]].push_back({U[i],W[i]});
      if(W[i]>ma) ma=W[i];
      if(U[i]!=0) sub2=0;
      if(!sub2) continue;
      if(W[i]<m1.w){
        m3=m2,m2=m1,m1={V[i],W[i]};
      }else if(W[i]<m2.w){
        m3=m2,m2={V[i],W[i]};
      }else if(W[i]<m3.w){
        m3={V[i],W[i]};
      }
    }
    if(sub1){
      for(int i=0;i<N;i++){
        if(g[i].size()>2) sub1=0;
        if(g[i].size()<2) cycle=0;
      }
    }
    if(!sub1 && !sub2){
      for(int i=0;i<n;i++){
        sort(g[i].begin(),g[i].end());
      }
    }
    // printf("%d %d\n%d %d\n%d %d\n",m1.u,m1.w,m2.u,m2.w,m3.u,m3.w);
    return ;
}
 
int subtask2(int X,int Y){
  if(n<=3) return -1;
  if(X!=0 && Y!=0){
    if(X!=m1.u && Y!=m1.u){
      return max(g[X][0].w,max(g[Y][0].w,m1.w));
    }else if(X!=m2.u && Y!=m2.u){
      return max(g[X][0].w,max(g[Y][0].w,m2.w));
    }else if(X!=m3.u && Y!=m3.u){
      return max(g[X][0].w,max(g[Y][0].w,m3.w));
    }
  }else{
    if(Y==0) swap(X,Y);
    //X==0
    if(Y==m1.u || Y==m2.u || Y==m3.u){
      return m3.w;
    }else{
      return max(g[Y][0].w,m2.w);
    }
  }
  return -1;
}
 
int subtask1(int X,int Y){
  if(cycle) return ma;
  else return -1;
}
 
int dijkstra(int X,int Y){
  for(int i=0;i<n;i++){
    dis[0][0][i]=dis[0][1][i]=dis[1][0][i]=dis[1][1][i]=MAX;
  }
  if(!h.empty()) h.pop();
  dis[0][1][X]=0;
  //int u,w,la,ch
  int nw;
  h.push({X,0,-1,1});
  while(!h.empty()){
   now=h.top();
   h.pop();
   if(now.u==Y) continue;
   if(now.u==X && now.la!=-1) continue;
  //  printf("%d %d %d %d\n",now.u,now.w,now.la,now.ch);
   for(auto x: g[now.u]){
      if(x.u==now.la) continue;
      nw=max(x.w,now.w);
      if(nw<dis[0][now.ch][x.u]){
        dis[1][now.ch][x.u]=dis[0][now.ch][x.u];
        dis[0][now.ch][x.u]=nw;
        h.push({x.u,nw,now.u,now.ch});
      }else if(nw<dis[1][now.ch][x.u]){
        dis[1][now.ch][x.u]=nw;
        h.push({x.u,nw,now.u,now.ch});
      }
   }
   if(now.ch && now.la!=Y && now.la!=X){
      if(now.w<dis[1][0][now.la]){
        dis[1][0][now.la]=now.w;
        h.push({now.la,now.w,now.u,0});
      }
   } 
  }
  int a,b,c;
  a=b=c=MAX;
  // printf("%d %d %d %d\n",dis[0][0][Y],dis[0][1][Y],dis[1][0][Y],dis[1][1][Y]);
  if(min(dis[1][0][Y],dis[1][1][Y])!=MAX) a=max(min(dis[0][0][Y],dis[0][1][Y]),min(dis[1][0][Y],dis[1][1][Y]));
  if(g[Y].size()>=3)b=max(min(dis[0][0][Y],dis[0][1][Y]),g[Y][2].w);
  if(g[X].size()>=3)c=max(min(dis[0][0][Y],dis[0][1][Y]),g[X][2].w);
  a=min(a,min(b,c));
  if(a==MAX) return -1;
  return a;
}
 
int getMinimumFuelCapacity(int X, int Y) {
  //min path ที่มี node อยู่ระหว่าง path กับถนนที่เชื่อมกันโหนดตรงกลาง
  //min path 2 path
  //min path + ลูกของ u หรือ v ที่ไม่อยู่ใน path 2 โนหด (u ทั้งคู่ / v ทั้งคู่)
  if(sub2) return subtask2(X,Y);
  else if(sub1) return subtask1(X,Y);
  else return dijkstra(X,Y);
  return 0;
}