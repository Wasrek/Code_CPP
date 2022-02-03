#include<bits/stdc++.h>
using namespace std;
long long v[50010],dp[50010][2];
int main(){
    long long q,n,k,m,i,j;
    long long s;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld %lld",&n,&k,&m);
        s=-1e18;
        dp[0][1]=1e18;
        for(i=1;i<=n;i++){
            scanf("%lld",&v[i]);
            if(i>=m)s=max(s,v[i-m]);
            v[i]+=v[i-1];
            if(i>=m)dp[i][1]=v[i]-s;
            else dp[i][1]=1e18;
            dp[i][1]=min(dp[i][1],dp[i-1][1]);
        }
        for(i=2;i<=k;i++){
            s=-1e18;
            dp[m*i+i-2][i%2]=1e18;
            for(j=m*i+i-1;j<=n;j++){
                s=max(s,v[j-m]-dp[j-m-1][(i+1)%2]);
                dp[j][i%2]=v[j]-s;
                dp[j][i%2]=min(dp[j][i%2],dp[j-1][i%2]);
            }
        }
        printf("%lld\n",v[n]-dp[n][k%2]);
    }
    return 0;
}
