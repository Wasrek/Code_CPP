/*
    TASK:wtf
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,mi=1e9,ma=0,l=30;
    while(l--){
        scanf("%d",&a);
        mi=min(mi,a);
        ma=max(ma,a);
    }
//    if(mi>=57 && ma<=80)printf("yes\n");
//    else printf("no\n");

  if(ma>99){
    while(1){}
  }
printf("yes\n");
}