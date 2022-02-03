#include "blindwalk.h"
#include<bits/stdc++.h>
#include <vector>
// #include "grader.cpp"
using namespace std;
long long a[4]={2596418101,840634349,590846489};
int fintyp(long long now){
  if(now==2596418101) return 1;
  if(now==840634349) return 2;
  return 3;
}
struct A{
  int i;
  long long v; 
  bool operator <(const A & o) const{
    return v<o.v;
  }
};
struct B{
  int i1,i2,cnt;
} pat[550];
vector<A> g;
vector<vector<int>> build_graph(int N)
{
  vector<vector<int>> out;
  long long now,cnt,ma=0;
  int mai;
  for(int i=1;i<N;i++){
    now=ask(0,i);
    g.push_back({i,now});
  }
  sort(g.begin(),g.end());
  int ti=fintyp(g[0].v)-1;
  for(auto x: g){
    pat[x.v/a[ti]].cnt++;
    if(pat[x.v/a[ti]].cnt==1) pat[x.v/a[ti]].i1=x.i;
    else pat[x.v/a[ti]].i2=x.i;
    ma=max(ma,x.v/a[ti]);
  }
  // if(pat[N-1].cnt){
  //   for(int i=0;i<g.size();i++){
  //     if(i==0){
  //       out.push_back(vector<int>{0,g[i].i,ti+1});
  //     }else{
  //       out.push_back(vector<int>{g[i-1].i,g[i].i,ti+1});
  //     }
  //   } 
  // }else{
    out.push_back(vector<int>{0,pat[1].i1,ti+1});
    out.push_back(vector<int>{0,pat[1].i2,ti+1});
    int ch=0;
    int l1=pat[1].i1;
    int l2=pat[1].i2;
    for(int i=2;i<=ma;i++){
      if(pat[i].cnt==1){
        if(!ch){
          ch=1;
          now=ask(pat[i].i1,l1);
          if(now==a[ti]){
            out.push_back(vector<int>{l1,pat[i].i1,ti+1});
          }else out.push_back(vector<int>{l2,pat[i].i1,ti+1});
          l1=pat[i].i1;
        }else{
          out.push_back(vector<int>{l1,pat[i].i1,ti+1});
          l1=pat[i].i1;
        }
      }else{
        now=ask(pat[i].i1,l1);
        if(now==a[ti]){
          out.push_back(vector<int>{l1,pat[i].i1,ti+1});
          out.push_back(vector<int>{l2,pat[i].i2,ti+1});
          l1=pat[i].i1;
          l2=pat[i].i2;
        }else{
          out.push_back(vector<int>{l1,pat[i].i2,ti+1});
          out.push_back(vector<int>{l2,pat[i].i1,ti+1});
          l1=pat[i].i1;
          l2=pat[i].i2;
        }
      }
    // }
  }
  return out;
}
