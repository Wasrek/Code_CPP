#include<vector>
#include "meeting.h"
#include <bits/stdc++.h>
// #include "grader.cpp"
using namespace std;

const int SIZE= 1e5+5;
struct A{
	int i;
	long long w;
};
set< int > g[SIZE];
vector< A > gg[SIZE];
int sz[SIZE], P[SIZE][22], lvl[SIZE], par[SIZE][22], ans[SIZE], nn,root,dep[SIZE],leng[SIZE][22];
long long dis[SIZE];
void dfs(int u, int p){
    P[u][0]=p;
    lvl[u]= (p>-1) ? lvl[p]+1 : 0;
    for(auto x: gg[u]){
        if(x.i==p) continue;
        dis[x.i]=dis[u]+x.w;
		dfs(x.i,u);
    }
	return ;
}

void sub_dfs(int u, int p){
    nn++;
    sz[u]= 1;
    for(int x: g[u]){
        if(x==p) continue;
        sub_dfs(x,u);
        sz[u]+= sz[x];
    }
}

int getCentroid(int u, int p){
    for(int x: g[u]){
        if(x==p) continue;
        if(sz[x]>nn/2)
            return getCentroid(x, u);
    }
    return u;
}

void decompose(int u, int p){
    nn= 0;
    sub_dfs(u,-1);
    int centroid= getCentroid(u,-1);
    par[centroid][0]= p;
	dep[centroid] = (p>-1)? dep[p]+1:0;
    for(int x: g[centroid]){
        g[x].erase(centroid);
        if(x==p) continue;
        decompose(x,centroid);
    }
    g[centroid].clear();
}

int lca_query(int p, int q) {
    if(lvl[p]<lvl[q])swap(p,q);
	int diff=lvl[p]-lvl[q];
	for(int i=0;i<=19;i++){
		if(diff>>i & 1) p=P[p][i];
	}
    if (p == q) return p;
    for (int i = 19; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return P[p][0];
}

int lca_centr(int p, int q) {
    if(dep[p]<dep[q])swap(p,q);
	int diff=dep[p]-dep[q];
	for(int i=0;i<=19;i++){
		if(diff>>i & 1) p=par[p][i];
	}
    if (p == q) return p;
    for (int i = 19; i >= 0; i--)
        if (par[p][i] != -1 && par[p][i] != par[q][i])
            p = par[p][i], q = par[q][i];

    return par[p][0];
}

long long getDist(int p, int q){
    int lca= lca_query(p,q);
    // find dist p to lca and q to lca
	return dis[p]+dis[q]-(dis[lca]*2);
}

long long find(int a,int b,int c){
	int anc=lca_centr(lca_centr(a,b),lca_centr(b,c));
	int u;
	u=a;
	while(u!=-1){
        now=min(now,max(getDist(u,a),max(getDist(u,b),getDist(u,c))));
		u= par[u][0];
    }
	u=b;
	while(u!=-1){
        now=min(now,max(getDist(u,a),max(getDist(u,b),getDist(u,c))));
		u= par[u][0];
    }
	u=c;
	while(u!=-1){
        now=min(now,max(getDist(u,a),max(getDist(u,b),getDist(u,c))));
		u= par[u][0];
    }
	return now;
}

vector<int> best_meeting(int N, int Q,
			 vector<vector<int>>& roads,
			 vector<int>& lengths,
			 vector<int>& a,
			 vector<int>& b,
			 vector<int>& c)
{
	vector<int> ans;
	for(int i=0;i<N-1;i++){
		g[roads[i][0]].insert(roads[i][1]);
		g[roads[i][1]].insert(roads[i][0]);
		gg[roads[i][0]].push_back({roads[i][1],lengths[i]});
		gg[roads[i][1]].push_back({roads[i][0],lengths[i]});
	}
	lvl[0]= 0;
    dfs(0,-1);
    for(int j=1; j<=19;j++){
        for(int i=0;i<N;i++){
            if(P[i][j-1]!=-1)
                P[i][j]= P[P[i][j-1]][j-1];
        }
    }
	decompose(0,-1);
	//centroid lca
	for(int j=1; j<=19;j++){
        for(int i=0;i<N;i++){
            if(par[i][j-1]!=-1){
                par[i][j]= par[par[i][j-1]][j-1];
				leng[i][j]=getDist(i,par[i][j]);
			}
        }
    }
	
	// printf("%d",root);
	for(int i=0;i<Q;i++){
		ans.push_back(find(a[i],b[i],c[i]));
	}
  	return ans;
}
/*
10 10
0 1 1
1 2 2
3 2 3
2 4 2
7 6 5
4 6 4
4 5 6
5 8 4
5 9 3
0 3 6
0 3 1
4 8 9
6 8 9
1 2 6
1 2 3
4 5 6
2 3 4
6 7 8
0 9 2
*/
