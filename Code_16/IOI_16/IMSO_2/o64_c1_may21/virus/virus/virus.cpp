#include "virus.h"
#define MOD 1000000007
#include<bits/stdc++.h>
using namespace std;
// #include "grader.cpp"
int ans[310];
int n, x, y;
void initialize(int N, int X, int Y) {
  n = N, x = X, y = Y;
  vector< int > temp,ini;
  for(int i=1;i<=N;i++){
    if(i!=X && i!=Y){
      temp.push_back(i);
    }
  }
  ini=temp;
  int ch=0,cnt=0;
  while(temp!=ini || !ch){
    ch=1;
    cnt=0;
    for(int i=0;i<n-2;i++){
      // printf("%d ",temp[i]);
      if(i==0){
        if((temp[i]>x && temp[i]>temp[i+1]) || (temp[i]<x && temp[i]<temp[i+1])) cnt++;
      }else if(i==n-3){
        if((temp[i]>temp[i-1] && temp[i]>y) || (temp[i]<temp[i-1] && temp[i]<y)) cnt++;
      }else{
        if((temp[i]>temp[i-1] && temp[i]>temp[i+1]) || (temp[i]<temp[i-1] && temp[i]<temp[i+1])) cnt++;
      }
    }
    // printf("%d\n",cnt);
    ans[cnt]++;
    ans[cnt]%=MOD;
    next_permutation(temp.begin(),temp.end());
  }
}

int ask(int L) {
  return ans[L];
}