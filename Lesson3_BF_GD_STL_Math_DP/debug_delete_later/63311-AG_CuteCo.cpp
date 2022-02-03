#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define x first
#define y second

using namespace std;

typedef long long i64;
typedef pair<int,int> pii;
typedef pair<i64,i64> pll;

const int mod = 1000000007;

int dp[10002];

int play(int n, int m){
	int i, j;
	for(i = 1; i <= n; ++i){
		dp[i] = 0;
	}
	dp[0] = 1;
	for(i = 1; i <= n; ++i){
		int s = dp[i-1];
		if(i > m) s = (s-dp[i-1-m]+mod)%mod;
		dp[i] = (s+dp[i-1])%mod;
	}
	return (dp[n]-dp[n-1]+mod)%mod;
}

int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		int n, k, m;
		scanf("%d %d %d",&n,&k,&m);
		int ans = (play(n,k)-play(n,m-1)+mod)%mod;
		printf("%d\n",ans);
	}
	return 0;
}
