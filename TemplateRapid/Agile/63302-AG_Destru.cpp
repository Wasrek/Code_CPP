#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 5e4+10;

ll qs[mxN], dp[2][mxN], mn[2][mxN];
/*
   qs[r] + (dp[i&1^1][l-1]-qs[l]);
   mn[k][r] = min ( for l in [i*m+i => r]  (dp[k][l-1]-qs[l]));
*/
void solve() {
	int n,k,m;
	scanf("%d %d %d", &n, &k, &m);
	for(int i=1; i<=n; ++i)
		scanf("%lld", &qs[i]), qs[i] += qs[i-1];
	for(int i=1; i<=n; ++i)
		mn[0][i] = min(mn[0][i-1], 0ll-qs[i]);
	for(int i=1; i<=k; ++i) {
		dp[i&1][i*m+i-2]=1ll<<62;
		mn[i&1][i*m+i-2]=1ll<<62;
		for(int r=i*m+i-1; r<=n; ++r) {
			dp[i&1][r] = min(dp[i&1][r-1], qs[r] + mn[i&1^1][r-m]);
			mn[i&1][r] = min(mn[i&1][r-1], dp[i&1][r-1]-qs[r]);
		}
	}
	/*
	for(int i=1; i<=k; ++i) {
		dp[i&1][i*m+i-2]=1ll<<62;
		for(int r=i*m+i-1; r<=n; ++r) {
			dp[i&1][r] = dp[i&1][r-1];
			for(int l=(i-1)*m+(i-1); l+m<=r; ++l) {
				dp[i&1][r] = min(dp[i&1][r], dp[i&1^1][max(l-1, 0)] + qs[r]-qs[l]);
			}
		}
	}
	*/
	printf("%lld\n", qs[n]-dp[k&1][n]);
	memset(dp, 0, sizeof(dp));
	memset(mn, 0, sizeof(mn));
}
int main() {
	int q;
	scanf("%d", &q);
	while(q--)
		solve();
	return 0;
}

