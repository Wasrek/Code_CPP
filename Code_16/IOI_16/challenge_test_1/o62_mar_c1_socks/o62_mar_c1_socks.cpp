/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include "sockslib.h"

using namespace std;

vector< int > v;
int a[2500],ma[2500];
int main() {
  int n,l,r,tmp,itm,cou=0,pass=0,fwv;
  n = num();
  a[1]=1;
  v.push_back(1);
  for(int i=2;i<=(2*n);i++){
    v.push_back( i );
    a[i]=ask(v);
  }
  for(int i=1;i<=2*n;i++){
    if(ma[i]) {pass++;continue;}
    l=i,r=2*n;
    while(l<r){
      int mid=(l+r)/2;
      v.clear();
      for(int j=i+1;j<=mid;j++){
        if(ma[j]) continue;
        v.push_back(j);
      }
      tmp=ask(v);
      itm=a[mid]-a[i-1];
      if(tmp >= itm) r=mid;
      else l=mid+1;
    }
    match(i,l);
    ma[i]=1;
    ma[l]=1;
    cou++;
    if(cou==n) return 0;
  }
}

