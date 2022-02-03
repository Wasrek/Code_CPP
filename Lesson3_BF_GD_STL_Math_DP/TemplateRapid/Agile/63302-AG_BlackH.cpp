#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5+10;
int in[mxN], out[mxN], cnt=0;
int h[mxN];
vector<int> adj[mxN];
void dfs(int i, int p, int now) { // euler tour in time and out time
	in[i] = ++cnt;
	h[i] = now;
	for(auto& x : adj[i]) {
		if(x!=p) dfs(x, i, now+1);
	}
	out[i] = ++cnt;
}
// --SEGMENT--
struct node {
	pair<int, int> mn; // min(h, idx);
	pair<int, int> lz;
};
int n;
struct LAZY_SEG {
	node st[4*2*mxN];
	void init() {
		for(int i=1; i<=4*n; ++i)
			st[i].mn.first = st[i].lz.first = (int)1e9;
	}
	void app(int i, int l, int r, pair<int, int> v) {
		st[i].mn = min(st[i].mn, v);
		st[i].lz = min(st[i].lz, v);
	}
	void push(int i, int l, int m, int r) {
		app(2*i, l, m, st[i].lz);
		app(2*i+1, m+1, r, st[i].lz);
		st[i].lz={(int)1e9, 0};
	}
	void upd(int ul, int ur, pair<int, int> v, int i=1, int l=1, int r=n) {
		if(ul<=l&&r<=ur) {
			app(i, l, r, v);
			return;
		}
		if(l>ur||r<ul) return;
		int m = (l+r)/2;
		if(st[i].lz.first!=1e9)
			push(i, l, m, r);
		if(ul<=m)
			upd(ul, ur, v, 2*i, l, m);
		if(m+1<=ur)
			upd(ul, ur, v, 2*i+1, m+1, r);
		st[i].mn = min(st[2*i].mn, st[2*i+1].mn);
	}
	pair<int, int> qry(int qi, int i=1, int l=1, int r=n) {
		if(l==qi && qi==r) return st[i].mn;
		if(l>qi||r<qi) return {(int)1e9, 0};
		int m = (l+r)/2;
		if(st[i].lz.first!=1e9)
			push(i, l, m, r);
		return min(qry(qi, 2*i, l, m), qry(qi, 2*i+1, m+1, r));
	}
} st;
// --SEGMENT--
int main() {
	int q;
	scanf("%d %d", &n, &q);
	for(int i=0; i<n-1; ++i) {
		int u,v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v), adj[v].push_back(u);
	}
	dfs(1, 1, 1);
	n*=2;
	st.init();
	while(q--) {
		int qt,u;
		scanf("%d %d", &qt, &u);
		if(qt==0)
			st.upd(in[u], out[u], {h[u], u});
		else {
			pair<int, int> ans = st.qry(in[u]);
			if(ans.first==1e9) printf("-1\n");
			else printf("%d\n", ans.second);
		}
	}
	return 0;
}

