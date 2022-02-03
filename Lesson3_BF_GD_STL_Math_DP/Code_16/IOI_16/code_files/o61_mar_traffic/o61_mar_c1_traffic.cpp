#include "traffic.h"
#include <vector>
#include <iostream>

using namespace std;

int n,k,ax1,ay1,ax2,ay2;

int disch(int x1,int y1,int x2,int y2,int d){
  return d-(abs(x1-x2)+abs(y1-y2));
}

void ansk(int x1,int y1,int x2,int y2){
  // printf("%d %d %d %d\n",x1,y1,x2,y2);
  if(ax1==0){
    ax1=x1,ax2=x2,ay1=y1,ay2=y2;
    if(k==1){
      traffic_report(ax1,ay1,ax2,ay2,0,0,0,0);
      exit(0);
    }
    return ;
  }
  traffic_report(ax1,ay1,ax2,ay2,x1,y1,x2,y2);
  exit(0);
}

void dcr(int x1,int y1,int x2,int y2,int cnt){
  // printf("r %d %d %d %d %d\n",x1,y1,x2,y2,cnt);
  if(abs(x1-x2)==1){
    ansk(x1,y1,x2,y2);
    return ;
  }
  int d,now;
  d=traffic_query(x1,y1,(x1+x2)/2,y2);
  now=disch(x1,y1,(x1+x2)/2,y2,d);
  if(now){
    dcr(x1,y1,(x1+x2)/2,y2,now);
  }
  cnt-=now;
  if(cnt){
    dcr((x1+x2)/2,y1,x2,y2,cnt);
  }
  return ;
}

void dcc(int x1,int y1,int x2,int y2,int cnt){
  // printf("c %d %d %d %d %d\n",x1,y1,x2,y2,cnt);
  if(abs(y1-y2)==1){
    ansk(x1,y1,x2,y2);
    return ;
  }
  int d,now;
  d=traffic_query(x1,y1,x2,(y1+y2)/2);
  now=disch(x1,y1,x2,(y1+y2)/2,d);
  if(now){
    // printf("l\n");
    dcc(x1,y1,x2,(y1+y2)/2,now);
  }
  cnt-=now;
  if(cnt){
    // printf("r\n");
    dcc(x1,(y1+y2)/2,x2,y2,cnt);
  }
  return ;
}

int main()
{
  int cou,r,c;
  traffic_init(&n,&k);
  for(int i=1;i<=n;i++){
    r=traffic_query(1,i,n,i);
    cou=disch(1,i,n,i,r);
    // printf("r %d %d\n",i,cou);
    if(cou){
      dcr(1,i,n,i,cou);
    }
    c=traffic_query(i,1,i,n);
    cou=disch(i,1,i,n,c);
    // printf("c %d %d\n",i,cou);
    if(cou){
      dcc(i,1,i,n,cou);
    }
  }
}
