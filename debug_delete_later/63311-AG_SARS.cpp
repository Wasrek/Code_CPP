#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define x first
#define y second

using namespace std;

typedef tuple<int,int,int> iii;
typedef long long i64;
typedef pair<int,int> pii;
typedef pair<i64,i64> pll;

const int N = 2005;

int dist[N];
int p[N];

struct node{
	int n;
	vector<int> mx;
	void init(int nn){
		n = nn;
		mx.resize(2*n);
	}
	void set(int x, int v){
		x += n-1;
		mx[x] = v;
		for(; x>>=1;){
			mx[x] = max(mx[x<<1],mx[x<<1|1]);
		}
	}
	int get(int L, int R){
		int ans = 0;
		for(L+=n-1,R+=n; L < R; L/=2,R/=2){
			if(L&1) ans=max(ans,mx[L++]);
			if(R&1) ans=max(ans,mx[--R]);
		}
		return ans;
	}
};

const int Q = 800005;
node seg;
vector<iii> comp;
vector<pii> st[N], en[N];
vector<pii> question[N];
int ans[Q];

int main(){
	int n, k, q;
	int i, j;
	scanf("%d%d%d",&n,&k,&q);
	for(i=1;i<=n;++i){
		scanf("%d",&p[i]);
		if(i>1){
			dist[i] = dist[i-1]+(p[i]-p[i-1]-1)/k;
		}
	}
	for(i=1;i<=n;++i){
		for(j=i;j<=n;++j){
			comp.eb(dist[j]-dist[i],i,j);
		}
	}
	sort(comp.begin(),comp.end());
	seg.init(int(comp.size()));
	/*
	for(i=1;i<=n;++i){
		for(j=i;j<=n;++j){
			iii x(dist[j]-dist[i],i,j);
			int idx = upper_bound(comp.begin(),comp.end(),x)-comp.begin();
			int v = j-i+1;
			st[i].eb(idx,v);
			en[j].eb(idx,v);
		}
	}
	*/
	for(i=0;i<int(comp.size());++i){
		int a, b, c;
		tie(c,a,b) = comp[i];
		st[a].eb(i+1,b-a+1);
		en[b].eb(i+1,b-a+1);
	}
	// sweep
	for(i=1;i<=q;++i){
		int a, b;
		scanf("%d%d",&a,&b);
		question[a+1].eb(b,i);
	}
	for(i=1;i<=n;++i){
		//printf("enter %d\n",i);
		for(pii e : st[i]){
			//printf("add (%d,%d)\n",e.x,e.y);
			seg.set(e.x,e.y);
		}
		for(pii e : question[i]){
			//printf("answering %d: ",e.y);
			int l = lower_bound(comp.begin(),comp.end(),iii(e.x+1,0,0))-comp.begin();
			//printf("%d %d\n",l,seg.get(1,l));
			ans[e.y] = seg.get(1,l);
		}
		for(pii e : en[i]){
			//printf("del (%d,%d)\n",e.x,e.y);
			seg.set(e.x,0);
		}
	}
	for(i=1;i<=q;++i) printf("%d\n",ans[i]);
	return 0;
}
