#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200100
int N,Q;
long long x[MAXN], y[MAXN], cid[MAXN], minl[MAXN], maxr[MAXN];
 
bool cmp(int a,int b)
{
	if(x[a]==x[b]) return y[a]<y[b];
	return x[a]<x[b];
}
 
 
int main()
{
    cin >> Q;
	while(Q--){
        cin >> N;
        for(int i=0;i<N;i++)
        {
            cin >> x[i] >> y[i];
            cid[i] = i;
        }
        sort(cid,cid+N,cmp);
        minl[0] = y[cid[0]];
        for(int i=1;i<N;i++)
            minl[i] = min(minl[i-1], y[cid[i]]);
        maxr[N-1] = y[cid[N-1]];
        for(int i=N-2;i>=0;i--)
            maxr[i] = max(maxr[i+1], y[cid[i]]);
        long long ans = 1;
        for(int i=0;i<N-1;i++)
            if(minl[i] > maxr[i+1])
                ans++;
        cout << ans << '\n';
    }
}