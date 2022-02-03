#include "combo.h"
#include<bits/stdc++.h>
#include"grader.cpp"
using namespace std;
char cha[5]={'A','B','X','Y'};

std::string guess_sequence(int N) {
  std::string p = "",ans="";
  int coins;
  char a=cha[0],b=cha[1],x=cha[2],y=cha[3];
  p=ans+a+ans+b;
  coins=press(p);
  if(coins<1){
    p=ans+x;
    coins=press(p);
    if(coins<1){
      ans+=y;
    }
    else{
      ans+=x;
      swap(x,y);
    }
  }else{
    p=ans+a;
    coins=press(p);
    if(coins<1){
      ans+=b;
      swap(b,y);
    }else{
      ans+=a;
      swap(a,y);
    }
  }
  // a b x
  for (int i = 1; i < N;i+=2) {
    // cout<< ans<<'\n';
    // aa ab ax bb ba bx xx xa xb
    if(i+3>N){
      if(i+1==N){
        p=ans+a+ans+b;
        coins=press(p);
        if(coins==i){
          ans+=x;
        }else{
          p=ans+a;
          coins=press(p);
          if(coins==i){
            ans+=b;
          }else{
            ans+=a;
          }
        }
      }else{
        p=ans+a+ans+b+a+ans+b+b+ans+b+x;
        coins=press(p);
        if(coins==i+2){// ba bb bx
          p=ans+b+a+ans+b+b;
          coins=press(p);
          if(coins==i+1){
            ans=ans+b+x;
          }else{
            p=ans+b+a;
            coins=press(p);
            if(coins==i+2){
              ans=ans+b+a;
            }else ans=ans+b+b;
          }
        }else if(coins==i+1){//ab aa ax
          p=ans+a+a+ans+a+b;
          coins=press(p);
          if(coins==i+1){
            ans=ans+a+x;
          }else{
            p=ans+a+a;
            coins=press(p);
            if(coins==i+2){
              ans=ans+a+a;
            }else ans=ans+a+b;
          }
        }else{//xa xb xx
          p=ans+x+a+ans+x+b;
          coins=press(p);
          if(coins==i+1){
            ans=ans+x+x;
          }else{
            p=ans+x+a;
            coins=press(p);
            if(coins==i+2){
              ans=ans+x+a;
            }else ans=ans+x+b;
          }
        }
      }
      break;
    }

    p=ans+a+a+ans+b+b+ans+a+x;
    coins = press(p);
    // cout<<p<<" "<<coins<<'\n';
    if(coins==i+2){//aa or bb or ax
      p=ans+a+ans+a+x;
      coins=press(p);
      if(coins==i){//bb
        ans=ans+b+b;
      }else if(coins==i+1){//aa
        ans=ans+a+a;
      }else{//ax
        ans=ans+a+x;
      }
    }else if(coins==i+1){
      // ab ba bx
      p=ans+a+b+ans+b+a+a+ans+b+a+b+ans+b+a+x;
      coins=press(p);
      if(coins==i+1){
        ans=ans+b+x;
      }else if(coins==i+2){
        ans=ans+a+b;
      }else{
        ans=ans+b+a;
      }
    }else{
      //xa xb xx
      p=ans+x+a+ans+x+b+a+ans+x+b+b+ans+x+b+x;
      coins=press(p);
      if(coins==i+1){
        ans=ans+x+x;
      }else if(coins==i+2){
        ans=ans+x+a;
      }else{
        ans=ans+x+b;
      }
    }
  }
  return ans;
}
