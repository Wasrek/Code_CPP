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
const int zero = 10000;
int dp[2][20007];

int main(){
	int i, j, k, n, q;
	scanf("%d",&q);
	while(q--){
		dp[0][zero] = 1;
		scanf("%d",&n);
		int sum = 0;
		for(i = 1; i <= n; ++i){
			int a;
			int now = (i&1);
			int pre = (now^1);
			scanf("%d",&a);
			for(j = 0; j <= 20000; ++j){
				int s = 0;
				if(j-a >= 0) s += dp[pre][j-a];
				if(j+a <= 20000) s += dp[pre][j+a];
				dp[now][j] = s%mod;
			}
			sum = (sum+dp[now][zero])%mod;
			dp[now][zero]++;
			if(dp[now][zero]>=mod) dp[now][zero]-=mod;
		}
		printf("%d\n",sum);
		memset(dp, 0, sizeof dp);
	}
	return 0;
}
