#include "reach.h"
#include<bits/stdc++.h>
// #include "grader.cpp"
using namespace std;
#define SIZE 100100
struct A{
	long long sum,l,r;
} seg[55*SIZE];
long long idx=0;
int root[SIZE*2],n;
vector< int > g[SIZE];
bool chask=1;
void upd(int l,int r,int &a,int b,int id){
	a=b;
    if(id<l || id>r) return ;
    a=++idx;
    seg[a]=seg[b];
    if(l==r){
		seg[a].sum++;
        seg[a].l=seg[a].r=0;
        return ;
    }
    int L,R,mid=(l+r)>>1;
    upd(l,mid,L,seg[a].l,id);
    upd(mid+1,r,R,seg[a].r,id);
    seg[a]={seg[L].sum+seg[R].sum,L,R};
    return ;
}
long long que(int l,int r,int a,int b,int now){
    if(r<a || l>b) return 0;
    if(l>=a && r<=b) return seg[now].sum;
    int mid=(l+r)>>1;
	return que(l,mid,a,b,seg[now].l)+que(mid+1,r,a,b,seg[now].r);
}
void initialize(int N) {
	n=N;
	return;
}

void add_arc(int u, int v) {
	u++,v++;
	if(u>v) swap(u,v);
	g[u].push_back(v);
	return;
}

bool is_reachable(int u, int v, int t) {
	if(chask){
		chask=0;
		root[0]=0;
		seg[0]={0,0,0};
		for(int i=1;i<=n;i++){
			upd(1,n,root[i],root[i-1],i);
			for(auto x: g[i]){
				upd(1,n,root[i],root[i],x);
			}
		}
		// for(int i=1;i<=n;i++){
		// 	printf("%d ",seg[root[i]].sum);
		// }
		// printf("\n");
	}
	u++,v++,t++;
	if(t<u) return true;
	if(u<=t && t<=v) return false;
	int qy;
	qy=que(1,n,v+1,t,root[u-1]);
	if(qy) return true;
	return false;
}
/*
6
6 
2 4 5 1
2 3 3 5
1 1 4
1 3 5
2 2 3 4
2 2 4 5
*/