#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define x first
#define y second

using namespace std;

typedef long long i64;
typedef pair<int,int> pii;
typedef pair<i64,i64> pll;

map<int,int> row, col, frow, fcol;
map<pii, int> rook;
i64 ans = 0;
int n, k, p;

void add(int x, int y, int z){
	ans -= n-fcol[row[y]];
	ans -= n-frow[col[x]];
	if(row[y] != col[x]) ans++;
	frow[row[y]]--;
	fcol[col[x]]--;
	row[y] ^= z;
	col[x] ^= z;
	frow[row[y]]++;
	fcol[col[x]]++;
	ans += n-fcol[row[y]];
	ans += n-frow[col[x]];
	if(row[y] != col[x]) ans--;
}

int main(){
	int i, j, l;
	scanf("%d%d%d",&n,&k,&p);
	frow[0] = fcol[0] = n;
	for(i = 1; i <= k; ++i){
		int x, y, z;
		scanf("%d %d %d",&x,&y,&z);
		rook[pii(x,y)] = z;
		add(x,y,z);
		//printf("%lld\n",ans);
	}
	while(p--){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int z =	rook[pii(x1,y1)];
		rook.erase(pii(x1,y1));
		add(x1,y1,z);
		rook[pii(x2,y2)] = z;
		add(x2,y2,z);
		printf("%lld\n",ans);
	}
	return 0;
}
