#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define x first
#define y second

using namespace std;

typedef long long i64;
typedef pair<int,int> pii;
typedef pair<i64,i64> pll;

const int N = 300004;
int p[N], di[N];
int find(int i){
	if(p[i] == i) return i;
	return p[i] = find(p[i]);
}

vector<int> g[N];
int dist[N];
bool vis[N];
queue<int> bfs;

int find_pair(int s){
	dist[s] = 0;
	bfs.push(s);
	pii mx(0,s);
	while(!bfs.empty()){
		int u = bfs.front();
		mx = max(mx, pii(dist[u],u));
		bfs.pop();
		for(int e : g[u]){
			if(dist[e]!=-1)continue;
			dist[e]=dist[u]+1;
			bfs.push(e);
		}
	}
	return mx.y;
}

void find_diameter(int s){
	static vector<int> member;
	member.clear();
	vis[s] = true;
	bfs.push(s);
	while(!bfs.empty()){
		int u = bfs.front();
		p[u] = s;
		member.eb(u);
		bfs.pop();
		for(int e : g[u]){
			if(vis[e]) continue;
			vis[e] = true;
			bfs.push(e);
		}
	}
	int a = find_pair(s);
	for(int e : member) dist[e] = -1;
	int b = find_pair(a);
	di[s] = dist[b];
	for(int e : member) dist[e] = -1;
}

int main(){
	int n, m, q;
	int i,j,k;
	memset(dist,-1,sizeof dist);
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;++i) p[i]=i;
	for(i=1;i<=m;++i){
		int a, b;
		scanf("%d%d",&a,&b);
		g[a].eb(b);
		g[b].eb(a);
	}
	for(i=1;i<=n;++i){
		if(!vis[i]){
			find_diameter(i);
		}
	}
	while(q--){
		int cmd,x;
		scanf("%d%d",&cmd,&x);
		if(cmd==1){
			printf("%d\n",di[find(x)]);
		}else{
			int y;
			scanf("%d",&y);
			x = find(x);
			y = find(y);
			if(x == y) continue;
			int nd = max({di[x],di[y],1+(di[x]+1)/2+(di[y]+1)/2});
			p[y] = x;
			di[x] = nd;
		}
	}
	return 0;
}
