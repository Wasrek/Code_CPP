#include <vector>
#include "dual.h"
#include<bits/stdc++.h>
// #include "grader.cpp"
using namespace std;
int fw[3][10000100];
void upd(int a,int b,int r){
  for(int i=a;i<=10000010;i+=(i&-i)){
    fw[r][i]+=1;
  }
  for(int i=b;i<=10000010;i+=(i&-i)){
    fw[r][i]-=1;
  }
}
int que(int u,int r){
  int sum=0;
  for(int i=u;i>0;i-=(i&-i)){
    sum+=fw[r][i];
  }
  return sum;
}
struct A{
  int v,i,le;
  bool operator <(const A& o) const{
    if(v!=o.v) return v>o.v;
    return i>o.i;
  }
};
priority_queue< A > h;
long long dual_fuel(int n,int v,vector<int> &a, vector<int> &b) {
  long long ans=0;
  int now,ma=-1,mav=1;
  A tp;
  for(int i=1;i<=n;i++){
    h.push({a[i-1],i,v});
    while(!h.empty()){
      if(h.top().le<=0 || h.top().i<=ma){
        h.pop();
        continue;
      }
      mav=max(mav,h.top().i);
      ans+=h.top().v;
      upd(h.top().i,i+1,0);
      tp=h.top();
      tp.le--;
      if(que(mav,0)==v) ma=mav;
      h.pop();
      if(tp.le>0 && tp.i>ma) h.push(tp);
      break;
    }
  }
  ma=-1,mav=1;
  while(!h.empty()) h.pop();
  for(int i=1;i<=n;i++){
    h.push({b[i-1],i,v});
    while(!h.empty()){
      if(h.top().le<=0 || h.top().i<=ma){
        h.pop();
        continue;
      }
      mav=max(mav,h.top().i);
      ans+=h.top().v;
      upd(h.top().i,i+1,1);
      tp=h.top();
      tp.le--;
      if(que(mav,1)==v) ma=mav;
      h.pop();
      if(tp.le>0 && tp.i>ma) h.push(tp);
      break;
    }
  }
  return ans;
}