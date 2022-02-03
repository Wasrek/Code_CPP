#include "onlineshop.h"
#include <bits/stdc++.h>
// #include "grader.cpp"
using namespace std;
void sell_all(int N)
{
  int now=300000;
  bool ch;
  for(int i=0; i<N; i++){
    ch=sell_price(now);
    if(ch==true){
      now+=(((11*i)%6)*60);
      now=min(1000000,now);
    }else{
      now-=(((11*i)%6)*150);
      now=max(1000,now);
    }
  }
}
