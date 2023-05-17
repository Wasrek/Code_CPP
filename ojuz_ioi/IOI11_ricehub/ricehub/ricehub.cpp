#include<bits/stdc++.h>
#include "grader.cpp"
#include "ricehub.h"
using namespace std;
int besthub(int R, int L, int X[], long long B)
{
  long long now=0,temp;
  int ans=0;
  for(int i=0, j=0;i<R && j<R;i++){
    if(j<i)j=i,now=0;
    while(j<(R-1)){//move j
      temp=(X[j+1]-X[(i+j+1)>>1]);
      if(now+temp<=B) j++,now+=temp;
      else break;
    }
    // printf("%d %d %d\n",i,j,now);
    ans=max(ans,j-i+1);
    if(j==R-1) break;
    now-=X[(i+j+1)>>1]-X[i];
  }                        
  return ans;
}