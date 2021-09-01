#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define x first
#define y second

using namespace std;

typedef long long i64;
typedef pair<int,int> pii;
typedef pair<i64,i64> pll;

const int N = 30004;

int fw[N];
int n;
void add(int i, int j){
	while(i <= n){
		fw[i] += j;
		i += (i&-i);
	}
}
int get(int i){
	int sum = 0;
	while(i){
		sum += fw[i];
		i -= (i&-i);
	}
	return sum;
}

int mark[N];
int nxt[N];
int num[N];

int ans[N];
vector<int> g[N];

int main(){
	int i, j, k;
	scanf("%d",&n);
	for(i = 1; i <= n; ++i){
		scanf("%d",&num[i]);
		mark[i] = n+1;
	}
	for(i = n; i > 0; --i){
		nxt[i] = mark[num[i]];
		mark[num[i]] = i;
	}
	for(i = 1; i <= n; ++i){
		if(mark[i] == n+1) continue;
		add(mark[i], 1);
	}
	for(i = 1; i <= n; ++i){
		g[1].eb(i);
	}
	for(i = 1; i <= n; ++i){
		//printf("%d\n",i);
		for(int e : g[i]){
			int l = i, r = n;
			while(l < r){
				int m = ((l+r+1)/2);
				int s = get(m);
				if(s <= e) l = m;
				else r = m-1;
			}
			++ans[e];
			g[l+1].eb(e);
		}
		g[i].clear();
		add(i, -1);
		if(nxt[i] != n+1){
			add(nxt[i], 1);
		}
	}
	for(i = 1; i <= n; ++i) printf("%d ",ans[i]);
	return 0;
}
