/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	:
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define allst(x,y) (x).begin()+y,(x).end()
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int MAX_INT = 1e9;
const LL MAX_LL = 1e18;
LL minN(vector<LL > a){
	LL minn = 1e18;
	for(auto x:a)
		minn = min(minn,x);
	return minn;
}
LL maxN(vector<LL > a){
	LL maxx = -1e18;
	for(auto x:a)
		maxx = max(maxx,x);
	return maxx;
}
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
priority_queue<LL > heap;
map<int ,int > mapp;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int m,n,v;
	LL sum = 0;
	cin >> m >> n;
	for(int i=1;i<=m;i++){
		cin >> v;
		heap.push(v/2);
		mapp[v]++;
	}
	for(int i=1;i<=n;i++){
		while(!heap.empty()){
			auto now = heap.top();
			heap.pop();
			if(mapp[now*2] == 0 && mapp[now*2+1] == 0)	continue;
			if(i%3){
				// printf("%d %d %d\n",now,mapp[now*2],mapp[now*2+1]);
				if(mapp[now*2+1]){
					// printf("case1\n");
					sum+=now*2+1;
					mapp[now*2+1]--;
					mapp[now*2]++;
					heap.push(now);
					break;
				}else if(mapp[now*2]){
					// printf("case2\n");
					sum+=now*2;
					mapp[now*2]--;
					mapp[now*2-1]++;
					if(mapp[now*2]!=0)	heap.push(now);
					if(now!=1)			heap.push(now-1);
					break;
				}
			}else{
				sum+=now;
				if(mapp[now*2]){
					mapp[now*2]--;
					mapp[now*2-1]++;
					if(mapp[now*2]!=0)	heap.push(now);
					if(now!=1)			heap.push(now-1);
					break;
				}else if(mapp[now*2+1]){
					mapp[now*2+1]--;
					mapp[now*2]++;
					heap.push(now);
					break;
				}
			}
		}
		// printf("%d\n",sum);
	}
	cout << sum << '\n';
	return 0;
}