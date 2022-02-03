#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5+10;

int n, ans=0, deg[mxN];
int edgesz=0, nodesz=0; // compress edge
int Node[mxN];
bool HeadNode[mxN];
vector<pair<int, int>> adj[mxN];
vector<tuple<int, int, int>> adj2[mxN];
void cutleaf() { // find cycle (topological sort);
	queue<int> q;
	for(int i=1; i<n; ++i) {
		if(deg[i]==1) q.push(i);
	}
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(auto& x : adj[u]) {
			if(deg[x.first]==1) continue;
			ans += x.second*2;
			if(x.first==0) continue;
			if(--deg[x.first]==1)
				q.push(x.first);
		}
	}
}
map<vector<int>, int> pathmap; // pathmap -> new edge
void compress() {
	deg[0]=2; // <- to check
	HeadNode[0] = 1;
	Node[0] = nodesz++;
	for(int i=1; i<n; ++i) {
		if(deg[i]>=3) 
			HeadNode[i]=1, Node[i]=nodesz++;
	}
	for(int i=0; i<n; ++i) {
		if(!HeadNode[i]) continue;
		int cycle=0;
		for(auto& x : adj[i]) {
			int v = x.first, w = x.second;
			if(deg[v]==1) continue;
			vector<int> path;
			path.push_back(i), path.push_back(v);
			int par=i, now=v, sum=w;
			while(!HeadNode[now]) { // travel until found headnode
				for(auto& y : adj[now]) {
					if(deg[y.first]==1 || y.first==par) continue;
					sum += y.second;
					par = now, now = y.first;
					break;
				}
				path.push_back(now);
			}
			if(i==now) { //cycle detech
				cycle += sum;
				continue;
			}
			int startNode = Node[i], endNode = Node[now];
			if(endNode > startNode)
				reverse(path.begin(), path.end());
			if(pathmap.find(path)==pathmap.end()) {
				pathmap.insert({path, ++edgesz});
				//cout << edgesz << " : (" << i << ", " << startNode << ")->( " << now << ", " << endNode << ") = " << sum << "\n";
				adj2[startNode].emplace_back(endNode, sum, edgesz-1);
				adj2[endNode].emplace_back(startNode, sum, edgesz-1);
			}
		}
		ans += cycle/2;
	}
}

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq; // tuple<weight, node, bitmask>
int d[1<<11][12];
void Dijkstra() {
	memset(d, 0x3f, sizeof(d));
	d[0][0]=0;
	pq.emplace(0, 0, 0);
	while(!pq.empty()) {
		int w,u,bit;
		tie(w, u, bit) = pq.top(); pq.pop();
		for(auto& x : adj2[u]) {
			int nx_node, nx_w, nx_mask;
			tie(nx_node, nx_w, nx_mask)=x;
			if(d[bit|(1<<nx_mask)][nx_node] > w+nx_w) {
				d[bit|(1<<nx_mask)][nx_node] = w+nx_w;
				pq.emplace(w+nx_w, nx_node, bit|(1<<nx_mask));
			}
		}
	}
}
int main() {
	int m;
	scanf("%d %d", &m, &n);
	while(m--) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
		++deg[u], ++deg[v];
	}
	cutleaf();
	compress();
	Dijkstra();
	printf("%d\n", d[(1<<edgesz)-1][0]+ans);
	return 0;
}

