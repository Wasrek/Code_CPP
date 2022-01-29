#include "emergency.h"
// #include <cstdio>


#include<bits/stdc++.h>
using namespace std;
struct A{
	int u,v;
};
struct B{
	long long ho,ce,ma;
};
vector< A > g[200010];
int h[200010],c[200010];
long long ans=0;
B dfs(int now,int last){ 
	// printf("%d %d\n",now,last);
  B ch,n;
	n.ho=n.ce=n.ma=-(1e9);
	if(h[now])n.ho=0;
	if(c[now])n.ce=0;
	for(auto x: g[now]){
		if(x.u==last) continue;
    // printf("%d\n",x.u);
		ch=dfs(x.u,now);
		n.ma=max(n.ho+ch.ce+x.v,max(n.ce+ch.ho+x.v,n.ma));
		n.ho=max(n.ho,ch.ho+x.v);
		n.ce=max(n.ce,ch.ce+x.v);
	}
  // printf("%d %d %d %d %d\n",now,last,n.ho,n.ce,n.ma);
	ans=max(ans,n.ma);
	return n;
}
int furthest(int N, int H, int K,
	     int roads[][2],
	     int lengths[],
	     int hospitals[],
	     int centers[])
{
	for(int i=0;i<N-1;i++){
    // printf("- %d %d %d\n",roads[i][0],roads[i][1],lengths[i]);
		g[roads[i][1]].push_back({roads[i][0],lengths[i]});
		g[roads[i][0]].push_back({roads[i][1],lengths[i]});
	}
	for(int i=0;i<H;i++){
		h[hospitals[i]]=1;
	}
	for(int i=0;i<K;i++){
		c[centers[i]]=1;
	}
	B df=dfs(0,-1);
	// printf("%lld\n",ans);
  	return ans;
}

