/*
    TASK:RT_Marathon
    LANG: CPP
    AUTHOR: Kersa
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,di,ti;
    bool operator<(const A&o)const{
        if(di!=o.di) return di>o.di;
        return ti>o.ti;
    }
};
priority_queue<A> q;
vector<A> g[100100];
int dis[100100];
int main()
{
	int n,m,k,t,ans=1<<30,di,u,ti,i,v,ans2=1<<30,pi,si;
	scanf("%d %d %d %d",&n,&m,&k,&t);
	for(i=0;i<m;i++){
        scanf("%d %d %d %d",&u,&v,&di,&ti);
        g[u].push_back({v,di,ti});
        g[v].push_back({u,di,ti});
	}
	int l=1,r=100001;
	while(l<r){
	    int mid=(l+r)/2;
        for(i=1;i<=n;i++)dis[i]=1<<30;
        dis[1]=0;
        q.push({1,0,0});
        while(!q.empty()){
            u=q.top().u,di=q.top().di,ti=q.top().ti,q.pop();
            if(u==n){break;}
            for(auto x:g[u]){
                if(x.ti+ti<=t && dis[x.u]>ti+x.ti &&x.di<=mid){
                    dis[x.u]=ti+x.ti,q.push({x.u,0,x.ti+ti});
                    if(x.u == n)    goto next;
                }
            }
        }
        next:;
        while(!q.empty())q.pop();
        if(dis[n]<=t)r=mid;
        else l=mid+1;
    }
	while(k--){
        scanf("%d %d",&pi,&si);
        if(si>=l)ans2=min(ans2,pi);
	}
	if(ans2==1<<30)printf("-1\n");
	else printf("%d\n",ans2);
    return 0;
}
/*
2 2 3 50
1 2 50 100
1 2 100 50
40 70
30 50
70 100
*/
