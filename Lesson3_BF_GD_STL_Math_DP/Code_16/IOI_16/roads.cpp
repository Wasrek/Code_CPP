#include "roads.h"
#include<bits/stdc++.h>
#include <vector>
// #include "grader.cpp"
using namespace std;
struct A{
  long long u,v,w;
  bool operator<(const A & o) const{
    return w<o.w;
  }
};
priority_queue< A > h1,h2;
int deg[100010];
std::vector<long long> minimum_closure_costs(int N, std::vector<int> U,
                                             std::vector<int> V,
                                             std::vector<int> W) {
  vector<long long> ans;
  long long sum=0;
  for(int i=0;i<N-1;i++){
    h1.push({U[i],V[i],W[i]});
    sum+=W[i];
    // printf("%lld %lld %lld %lld\n",U[i],V[i],W[i],i);
  }
  int k;
  ans.push_back(sum);
  while(!h1.empty()){
    ans.push_back(sum-h1.top().w);
    sum-=h1.top().w;
    k++;
    h1.pop();
  }
  for(int i=k;i<=N-1;i++) ans.push_back(0);
  return ans;
}
