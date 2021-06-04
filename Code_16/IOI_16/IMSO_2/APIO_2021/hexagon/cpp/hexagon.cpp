#include "hexagon.h"
#include<bits/stdc++.h>
#include <vector>
#include "grader.cpp"
using namespace std;
#define MOD 1000000007
int di[10]={0,-1,0,1,1,1,0},dj[10]={0,0,1,1,0,-1,-1};
map<pair<int,int>,bool> mp;
int draw_territory(int N, int A, int B,
                   std::vector<int> D, std::vector<int> L) {
  L[0]--;
  long long d,d1;
  d=L[0]+1;
  d1=L[0]+1+1;
  if(d%2==0) d/=2;
  else d1/=2;
  d=(d*d1)%MOD;
  d=(d*A)%MOD;

  long long n,n1,n21,b;
  n=L[0];
  n1=L[0]+1;
  n21=(2*L[0])+1;
  if(n%3==0){
    n/=3;
  }else if(n1%3==0){
    n1/=3;
  }else{
    n21/=3;
  }

  if(n%2==0){
    n/=2;
  }else if(n1%2==0){
    n1/=2;
  }else{
    n21/=2;
  }

  b=((((((n*n1)%MOD)*n21)%MOD)+(((n*(n-1))%MOD)/2)%MOD)*B)%MOD;
  return (d+b)%MOD;
}
/*
17 2 3
1 1
2 2
3 2
4 1
5 1
4 1
3 1
2 2
1 3
6 2
2 3
3 1
4 6
5 3
6 3
6 2
1 1
*/