#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long dp[10000010];
int main(){
	long long n,k=3,q;
	dp[0] = 1;
	for(long long i=1;i<=1e7;i++){
		dp[i] = dp[i-1];
		if(i>k)	dp[i]-=dp[i-k-1];
		dp[i]%=MOD,dp[i]+=MOD,dp[i]%=MOD;
		dp[i]+=dp[i-1];
		dp[i]%=MOD;
	}
	scanf("%lld",&q);
	while(q--){
        scanf("%lld",&n);
        n++;
        printf("%lld\n",(((dp[n]-dp[n-1]-1)%MOD)+MOD)%MOD);
	}
	return 0;
}
