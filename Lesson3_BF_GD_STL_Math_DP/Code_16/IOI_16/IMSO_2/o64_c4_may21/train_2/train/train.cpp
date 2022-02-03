#include<bits/stdc++.h>
#include "train.h"
#include <vector>
// #include "grader.cpp"
using namespace std;
#define SIZE 200100
struct A{
	bool la;
	int v;
};
int seg[SIZE*4],dp[SIZE];
A lazy[4*SIZE];
void build(int l,int r,int now)
{
    if(l==r)
    {
  		if(l!=1) seg[now]=2e9;
  		lazy[now].v=2e9;
  		lazy[now].la=0;
        return ;
    }
	lazy[now].v=2e9;
  	lazy[now].la=0;
    int mid=(l+r)>>1;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    seg[now]=min(seg[now*2],seg[now*2+1]);
}
void update(int l,int r,int a,int b,int now,int val)
{
    if(lazy[now].la)
    {
        if(l!=r)
        {
            lazy[now*2].la=1;
			lazy[now*2].v=min(lazy[now].v,lazy[now*2].v);
            lazy[now*2+1].la=1;
			lazy[now*2+1].v=min(lazy[now].v,lazy[now*2+1].v);
        }
        seg[now]=min(seg[now],lazy[now].v);
        lazy[now].la=0;
		lazy[now].v=2e9;
    }
    if(l>b || r<a)
        return ;
    if(l>=a && r<=b)
    {
		// printf("%d %d %d %d %d %d\n",l,r,a,b,seg[now],val);
        seg[now]=min(seg[now],val);
        if(l!=r){
            lazy[now*2].la=1;
			lazy[now*2].v=min(val,lazy[now*2].v);
            lazy[now*2+1].la=1;
			lazy[now*2+1].v=min(val,lazy[now*2+1].v);
		}
		return ;
    }
    int mid=(l+r)>>1;
    update(l,mid,a,b,now*2,val);
    update(mid+1,r,a,b,now*2+1,val);
    seg[now]=min(seg[now*2],seg[now*2+1]);
}
int query(int l,int r,int a,int b,int now)
{
    if(lazy[now].la)
    {
        if(l!=r)
        {
            lazy[now*2].la=1;
			lazy[now*2].v=min(lazy[now].v,lazy[now*2].v);
            lazy[now*2+1].la=1;
			lazy[now*2+1].v=min(lazy[now].v,lazy[now*2+1].v);
        }
        seg[now]=min(seg[now],lazy[now].v);
        lazy[now].la=0;
		lazy[now].v=2e9;
    }
    if(l>b || r<a)return 2e9;
    if(l>=a && r<=b)return seg[now];
    int mid=(l+r)>>1;
    return min(query(l,mid,a,b,now*2),query(mid+1,r,a,b,now*2+1));
}
int find_min_cost(int N, int M,
		  std::vector<int>& s,
		  std::vector<int>& t,
		  std::vector<int>& c)
{
	for(int i=0;i<=N;i++) dp[i]=2e9;
	dp[1]=0;
	build(1,N,1);
	int lb,ub,qy;
	for(int i=0;i<M;i++){
		s[i]++,t[i]++;
		qy=query(1,N,s[i],t[i],1);
		dp[t[i]]=min(dp[t[i]],c[i]+qy);
		// printf("%d %d %d %d\n",s[i],t[i],qy,dp[t[i]]);
		update(1,N,s[i],t[i],1,c[i]+qy);
	}
	if(dp[N]==2e9) return -1;
	return dp[N];
}
/*
7 7
0 2 10
1 3 50
2 6 200
2 4 30
4 6 200
3 6 10
0 6 1000
*/