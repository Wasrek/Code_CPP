#include<bits/stdc++.h>
#include "wirelib.h"
// #include "wirelib.cpp"
using namespace std;
int sol[100],now[100];
vector<int> pos;
void play(int l,int r,vector<int> g){
  if(l==r){
    for(auto x: g){
      sol[x]=l;
    }
    return ;
  }
  int mid=(l+r)/2;
  for(int i=l;i<=mid;i++){
    if(!now[i]) now[i]=cmd_C(i);
  }
  for(int i=mid+1;i<=r;i++){
    if(now[i]) now[i]=cmd_C(i);
  }
  vector<int> ll,rr;
  for(auto x: g){
    if(cmd_T(x)) ll.push_back(x);
    else rr.push_back(x);
  }
  play(l,mid,ll);
  play(mid+1,r,rr);
}
int main()
{
  int m = wire_init();
  for(int i=1;i<=m;i++){
    pos.push_back(i);
  }
  play(1,m,pos);
  cmd_D(sol);
  // for(int i=0; i<m; i++) {
  //   cmd_C(i+1);
  //   if(cmd_T(i+1)) {
  //     sol[i+1] = i+1;
  //   }
  //   cmd_C(i+1);
  // }
}
