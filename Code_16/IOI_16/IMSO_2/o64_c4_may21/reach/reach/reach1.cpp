#include "reach.h"
#include<bits/stdc++.h>
// #include "grader.cpp"
using namespace std;
#define SIZE 100100
int mi[SIZE],n;
int seg[4*SIZE];
void update(int l,int r,int a,int b,int now){
    if(l>a || r<a) return ;
    if(l==r){ seg[now]=b;return ;}
    int mid = (l+r)/2;
    update(l,mid,a,b,now*2);
    update(mid+1,r,a,b,now*2+1);
    seg[now]=min(seg[now*2],seg[now*2+1]);
}
int query(int l,int r,int a,int b,int now){
    if(r<a || l>b) return 2e9;
    if(l>=a && r<=b) return seg[now];
    int mid=(l+r)/2;
    return min(query(l,mid,a,b,now*2),query(mid+1,r,a,b,now*2+1));
}
void initialize(int N) {
	n=N;
    for(int i=1;i<=n;i++){
        mi[i]=2e9;
        update(1,n,i,2e9,1);
    }
	return;
}

void add_arc(int u, int v) {
    u++,v++;
	if(mi[v]<=u) return ;
    mi[v]=u;
    update(1,n,v,u,1);
    // printf("%d %d %d\n",query(1,n,v,v,1),v,u);
	return;
}

bool is_reachable(int u, int v, int t) {
	u++,v++,t++;
	if(t<u) return true;
	if(u<=t && t<=v) return false;
	int qy;
	qy=query(1,n,v+1,t,1);
    // printf("%d %d %d\n",qy,v+1,t);
	if(qy<=u-1) return true;
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