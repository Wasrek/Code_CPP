#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long dp[10000100];
int main(){
    int q,n;
    dp[2]=3;
    for(int i=3;i<=10000000;i++)dp[i]=(dp[i-1]*2+dp[i-2]*3)%mod;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        printf("%lld\n",dp[n]);
    }
    return 0;
}
