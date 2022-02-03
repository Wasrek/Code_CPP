#include "guess.h"

#include<bits/stdc++.h>

using namespace std;


vector<pair<int, char>> g;

int div2(int l,int n,int k){
  // printf("%d %d %d\n",l,n,k);
  if(n==1) return l;
  char c;
  if(n==2){
    c=ask({{l,'R'}});
    if(c=='R') return l;
    return l+1;
  }
  for(int i=l;i<=l+(n/3)-1;i++){
    g.push_back({i,'R'});
  }
  for(int i=l+(n/3);i<l+(n/3)*2;i++){
    g.push_back({i,'B'});
  }
  c = ask(g);
  g.clear();
  if(c=='R'){
    return div2(l,n/3,k);
  }
  if(c=='B'){
    return div2(l+(n/3),n/3,k);
  }
  if(c=='C'){
    return l+(n/3)*2;
  }
  if(n-((n/3)*2)==2){
    return l+(n/3)*2+1;
  }
  return div2(l+(n/3)*2,n-((n/3)*2),k);
}


int div1(int l,int n,int k){
  // printf("%d %d %d\n",l,n,k);
  if(n==1) return l;
  char c;
  if(n==2){
    c=ask({{l,'R'}});
    if(c=='R') return l;
    return l+1;
  }
  for(int i=l;i<=l+(n/2)-1;i++){
    g.push_back({i,'R'});
    //printf("%d ",i);
  }
  // for(auto x: g){
  //   printf(" (%d %c) ",x.first,x.second);
  // }
  // printf("\n");
  c = ask(g);
  g.clear();
  if(c=='R'){
    return div1(l,n/2,k);
  }
  if(c=='C'){
    return l+(n/2);
  }
  return div1(l+(n/2),n-(n/2),k);
}



int find_answer(int N, int K) {
  if(K==2) return div2(0,N,K);
  return div1(0,N,K);
  // for(int i=0;i<N;i++) g.push_back({i,'R'});
  // return div1(g,K);
}



