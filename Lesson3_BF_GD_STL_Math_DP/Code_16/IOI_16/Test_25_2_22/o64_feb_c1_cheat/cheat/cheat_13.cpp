#include "cheat.h"
#include<bits/stdc++.h>
using namespace std;
struct A{
  int a,b,t;
};
A mer[100010];
int p[200010],ch[200010],n=0,ti=0;
unordered_map< int,int > mp;
int fin(int i){
  if(p[i]==i || p[i]==0){
    p[i]=i;
    return i;
  }
  return p[i]=fin(p[i]);
}
int finb(int i){
  if(mp[i]==i || mp[i]==0){
    mp[i]=i;
    return i;
  }
  return mp[i]=finb(mp[i]);
}
void cheat(int p1, int p2)
{
  ti++;
  if(!ch[p1]) ch[p1]=1,p[p1]=p1;
  if(!ch[p2]) ch[p2]=1,p[p2]=p2;
  if(fin(p1)==fin(p2))return ;
  p[fin(p1)]=fin(p2);
  mer[++n]={p1,p2,ti};
}
int investigate(int p1, int p2)
{
  if(ch[p1]==0 || ch[p2]==0 || fin(p1)!=fin(p2)) return -1;
  int l=1,r=n;
  while(l<r){
    // printf("l r %d %d %d %d\n",mp[p1],mp[p2],p1,p2);
    int mid=(l+r)>>1;
    // printf("%d\n",mid);
    mp[p1]=p1;
    mp[p2]=p2;
    for(int i=1;i<=mid;i++){
      if(!mp[mer[i].a]) mp[mer[i].a]=mer[i].a;
      if(!mp[mer[i].b]) mp[mer[i].b]=mer[i].b;
      // printf("%d %d %d %d\n",mer[i].a,mer[i].b,finb(mp[mer[i].a]),finb(mp[mer[i].b]));
      mp[finb(mp[mer[i].a])]=finb(mp[mer[i].b]);
    }
    // printf("-- %d %d %d %d",finb(p1),finb(p2),p1,p2);
    if(finb(p1)==finb(p2) && mp[p1] && mp[p2]) r=mid;
    else l=mid+1;
    mp.clear(); 
  }
  // printf("%d\n",l);
  return mer[l].t;
}