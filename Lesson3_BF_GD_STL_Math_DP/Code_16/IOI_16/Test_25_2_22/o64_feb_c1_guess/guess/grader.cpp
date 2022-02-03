#include "guess.h"
#include <cstdio>
#include <cassert>
#include <utility>
#include <vector>



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


// int div1(int l,int n,int k){
//   // printf("%d %d %d\n",l,n,k);
//   if(n==1) return l;
//   char c;
//   if(n==2){
//     c=ask({{l,'R'}});
//     if(c=='R') return l;
//     return l+1;
//   }
//   for(int i=l;i<=l+(n/2)-1;i++){
//     g.push_back({i,'R'});
//     //printf("%d ",i);
//   }
//   // for(auto x: g){
//   //   printf(" (%d %c) ",x.first,x.second);
//   // }
//   // printf("\n");
//   c = ask(g);
//   g.clear();
//   if(c=='R'){
//     return div1(l,n/2,k);
//   }
//   if(c=='C'){
//     return l+(n/2);
//   }
//   return div1(l+(n/2),n-(n/2),k);
// }

int div3(vector<pair<int, char>> now,int k){
  if(now.size()==1) return now[0].first;
  g.clear();
  for(int i=0;i<now.size();i+=2) g.push_back({now[i].first,'R'});
  char c;
  c = ask(g);
  if(c=='R') {
    return div3(g,k);
  }
  g.clear();
  for(int i=1;i<now.size();i+=2) g.push_back({now[i].first,'R'});
  return div3(g,k);
}


int div1(vector<pair<int, char>> now,int k){
  // for(auto x: now){
  //   printf("%d ",x.first);
  // }
  // printf("\n");
  if(now.size()==1) return now[0].first;
  char c;
  if(now.size()==2){
    c=ask({{now[0].first,'R'}});
    if(c=='R') return now[0].first;
    return now[1].first;
  }
  g.clear();
  for(int i=0;i<now.size();i+=4) g.push_back({now[i].first,'R'});
  // for(auto x: g) printf("%d ",x.first);
  // printf("\n");
  c=ask(g);
  // printf("%c\n",c);
  if(c=='R'){
    return div3(g,k);
  }
  g.clear();
  if(c=='X'){
    for(int i=2;i<now.size();i+=4) g.push_back({now[i].first,'R'});
    return div3(g,k);
  }
  for(int i=1;i<now.size();i+=2) g.push_back({now[i].first,'R'});
  return div3(g,k);
}


int find_answer(int N, int K) {
  if(K==2) return div2(0,N,K);
  // return div1(0,N,K);
  for(int i=0;i<N;i++) g.push_back({i,'R'});
  return div1(g,K);
}







static int n, m, k;
static int cnt;



char ask(const vector<pair<int, char>> V) {
  cnt++;
  if (V.empty()) {
    return 'X';
  }
  assert(V.begin()->first >= 0 and V.rbegin()->first < n);
  for (int i = 0; i < V.size(); ++i) {
    if (i) {
      assert(V[i-1].first < V[i].first);
    }
    if (k == 1) {
      assert(V[i].second == 'R');
    } else {
      assert(V[i].second == 'R' or V[i].second == 'B');
    }
  }
  vector<char> tmp(n);
  for (auto x : V) {
    tmp[x.first] = x.second;
  }
  for (int i = 0; i < n; ++i) {
    if (tmp[i] == 0) {
      tmp[i] = 'X';
      if (i != 0) {
        if (tmp[i - 1] == 'R' or tmp[i - 1] == 'B') {
          tmp[i] = 'C';
        }
      }
      if (i != n - 1) {
        if (tmp[i + 1] == 'R' or tmp[i + 1] == 'B') {
          tmp[i] = 'C';
        }
      }
    }
  }
  return tmp[m];
}

int main() {
	assert(scanf("%d %d %d", &n, &m, &k) == 3);
  assert(m >= 0 and m < n);
  assert(k == 1 or k == 2);
	int result = find_answer(n, k);
  if (result == m) {
    printf("Correct!\n");
  } else {
    printf("Wrong!\n");
  }
  printf("called %d times\n", cnt);
	return 0;
}
