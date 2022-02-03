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
priority_queue< A > h1;
int deg[100010];
bool sub1=true,sub2=true;

std::vector<long long> subtask1(int N, std::vector<int> U,
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

struct B{
  int u,v,w;
  bool operator <(const B & o) const{
    return u<o.u;
  }
};
B h2[100010];
long long dp[100010];

std::vector<long long> subtask2(int N, std::vector<int> U,
                                             std::vector<int> V,
                                             std::vector<int> W) {

  vector<long long> ans;
  long long sum1=0,sum=0;
  for(int i=0;i<N-1;i++){
    h2[i]={U[i],V[i],W[i]};
    sum+=W[i];
    // printf("%lld %lld %lld %lld\n",U[i],V[i],W[i],i);
  }
  for(int i=0;i<N-1;i++){
    dp[i]=W[i];
    if(i>=1){
      dp[i]=max(dp[i],dp[i-1]);
    }
    if(i>=2){
      dp[i]=max(dp[i],dp[i-2]+W[i]);
    }
  }
  ans.push_back(sum);
  ans.push_back(sum-dp[N-2]);
  for(int i=2;i<=N-1;i++) ans.push_back(0);
  return ans;
}



std::vector<long long> minimum_closure_costs(int N, std::vector<int> U,
                                             std::vector<int> V,
                                             std::vector<int> W) {
  for(int i=0;i<N-1;i++){
    // h1.push({U[i],V[i],W[i]});
    if(V[i]<U[i])swap(U[i],V[i]);
    if(V[i]!=U[i]+1) sub2=false; 
    if(U[i]!=0) sub1=false;
    // printf("%lld %lld %lld %lld\n",U[i],V[i],W[i],i);
  }
  if(sub1) return subtask1(N,U,V,W);
  return subtask2(N,U,V,W);
}
