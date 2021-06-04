#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
#define N 60100
typedef long long int ll;
ll find(ll parent[], ll x)
{
    if (parent[x] == x)
        return x;
  
    parent[x] = find(parent, parent[x]);
  
    return parent[x];
}
void merge(ll parent[], ll size[],ll x, ll y)
{
    ll r1 = find(parent, x);
    ll r2 = find(parent, y);
  
    if (size[r1] < size[r2]) {
        parent[r1] = r2;
        size[r2] += size[r1];
    }
    else {
        parent[r2] = r1;
        size[r1] += size[r2];
    }
}
void generate(int n)
{
        ll i;
        ll parent[n + 1];
        ll size[n + 1];
  
        for (i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
  
        vector<pair<ll, ll> > Edges;
        vector<ll> weights;
  
        for (i = 1; i <= n - 1; i++) {
            ll x =  rnd.next(1,n);
            ll y = rnd.next(1,n);
  
            while (find(parent, x)
                   == find(parent, y)) {
  
                x = rnd.next(1,n);
                y = rnd.next(1,n);
            }
  
            merge(parent, size, x, y);
  
            Edges.push_back(make_pair(x, y));
            ll w = rnd.next(1,100000);
            weights.push_back(w);
        }
  
        for (i = 0; i < Edges.size(); i++) {
  
            cout << Edges[i].first << " " << Edges[i].second << " " << weights[i];
            cout << "\n";
        }
}


void lineartree(int n){
    for(int i=1;i<n;i++){
        cout<<i <<' '<<i+1<<' '<<rnd.next(1,100000)<<'\n';
    }
    return ;
}

int main(int argc,char* argv[]){
	registerGen(argc, argv, 1);
    int n,m,r,k,now,fr,la;
	int cnt = 0;
	int q = atoi(argv[++cnt]);
	int minN = atoi(argv[++cnt]);
	int maxN = atoi(argv[++cnt]);
	int minM = atoi(argv[++cnt]);
	int maxM = atoi(argv[++cnt]);
	int minK = atoi(argv[++cnt]);
	int maxK = atoi(argv[++cnt]);
	int linear = atoi(argv[++cnt]);
	n = rnd.next(minN,maxN);
	m = rnd.next(minM,maxM);
	cout<<q<<"\n";
	while(q>0){
		now=rnd.next(m*2+1,n);
		k = rnd.next(minK,maxK);
		cout<<n<<' '<<m<<' '<<m+(now-(m*2))<<' '<<k<<'\n';
		if(!linear) generate(n);
		else lineartree(n);
		for(int i=1;i<=m*2;i+=2){
			cout<<i<<' '<<i+1<<'\n';
		}
		for(int i=m*2+1;i<=now;i++){
			cout<<i<<' '<<rnd.next(1,i-1)<<'\n';
		}
		q--;
		for(int i=1;i<=k;i++){
			cout<<i;
			if(i!=k)    cout << ' ';
		}
		cout<<'\n';
	}
    return 0;
}