/*
	TASK:God of War
	LANG: CPP
	AUTHOR: KersaWC
	SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	long long v,w;
	bool operator<(const A&o) const{
		return w>o.w;
	}
};
vector< A > g[100010];
priority_queue<A> h;
long long dis[100010],dis2[100010];
int main(){
	int n,m,s,t,u,v,i;
	long long sum=0,ma=0,w;
	scanf("%d %d",&n,&m);
	scanf("%d %d",&s,&t);
	while(m--){
		scanf("%d %d %lld",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		sum+=w;
	}
	for(i=0;i<=n;i++)dis[i]=1<<30,dis2[i]=1<<30;
	h.push({s,0});
	dis[s]=0;
	while(!h.empty()){
		v=h.top().v;
		w=h.top().w;
		h.pop();
		for(auto x:g[v]){
			if(dis[x.v]<=dis[v]+x.w)continue;
			dis[x.v]=dis[v]+x.w;
			h.push({x.v,dis[x.v]});
		}
	}
	h.push({t,0});
	dis2[t]=0;
	while(!h.empty()){
		v=h.top().v;
		w=h.top().w;
		h.pop();
		for(auto x:g[v]){
			if(dis2[x.v]<=dis2[v]+x.w)continue;
			dis2[x.v]=dis2[v]+x.w;
			h.push({x.v,dis2[x.v]});
		}
	}
	for(int i=0;i<n;i++){
		for(auto x: g[i]){
			ma=max(ma,sum-dis[i]-dis2[x.v]);
		}
	}
	printf("%lld\n",ma);
	return 0;
}
