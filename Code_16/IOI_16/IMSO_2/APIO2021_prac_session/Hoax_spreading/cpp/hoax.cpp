#include "hoax.h"
#include<bits/stdc++.h>
#include <vector>
// #include "stub.cpp"
using namespace std;
struct LI{
  int s,e,i;
  bool operator<(const LI & o) const{
    if(s!=o.s) return s<o.s;
    return e<o.e;
  }
};
int p[200100],cnt[200100];
deque< LI > dq;
int finr(int i){
  if(p[i]==i) return i;
  return p[i]=finr(p[i]);
}
void init(int N, int S, std::vector<int> T,
          std::vector<std::vector<int>> A, std::vector<std::vector<int>> B) {
  for(int i=0;i<N;i++){
    for(int j=0;j<T[i];j++){
      dq.push_back({A[i][j],B[i][j],i+1});
    }
    p[i+1]=i+1;
  }
  sort(dq.begin(),dq.end());
  LI now=dq.front();
  dq.pop_front();
  while(!dq.empty()){
    // printf("%d %d %d\n",dq.front().s,dq.front().e,dq.front().i);
    if(dq.front().s<=now.e){
      p[finr(dq.front().i)]=finr(now.i);
      // printf("%d %d\n",dq.front().i,now.i);
    }
    if(dq.front().e>now.e){
      now=dq.front();
    }
    dq.pop_front();
  }
  for(int i=1;i<=N;i++){
    cnt[finr(i)]++;
  }
}

int count_users(int P) {
  return cnt[finr(P+1)];
}
/*
5 10 5
2
2 4 
7 9
1
1 3
1
1 1
1
9 10
1
5 6
0
1
2
3
4
*/