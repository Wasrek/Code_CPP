#include<bits/stdc++.h>
using namespace std;
#include "grader.cpp"
#include "cheat.h"
using namespace std;
#define f first
#define s second
int sz[200100],t=0;
bool ch=0;
pair<int,int> p[200100];
void init(){
    ch=1;
    for(int i=1;i<=200000;i++){
        sz[i]=1;
        p[i]={i,0};
    }
    return ;
}
int fr(int i){
    if(p[i].f==i) return i;
    return fr(p[i].f); 
}
void cheat(int p1, int p2)
{
    if(!ch) init();
    t++;
    p1=fr(p1); p2=fr(p2);
    if(p1==p2) return ;
    if(sz[p1]>sz[p2]) swap(p1,p2);
    p[p1]=make_pair(p2,t);
    sz[p2]+=p1;
}

int investigate(int p1, int p2)
{
    if(!ch) init();
    int l=0,r=t+1,mid,u,v;
    while(l<r){
        mid=(l+r)>>1;
        u=p1,v=p2;
        while(p[u].s!=0 && p[u].s<=mid) u=p[u].f;
        while(p[v].s!=0 && p[v].s<=mid) v=p[v].f;
        if(u==v) r=mid;
        else l=mid+1;
    }
    if(l==t+1) return -1;
    return l;
}

/*
5 4
C 1 2
C 2 1
C 3 1
C 4 100
I 3 2
I 1 100
C 3 4
I 1 100
I 1 2
*/