#include<bits/stdc++.h>
using namespace std;
long long v[50010],dp[50010][3];
int main(){
    int q,n,k,m,i,j;
    long long s;
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d",&n,&k,&m);
        s=-(long long)1e18;
        dp[0][1]=(long long)1e18;
        for(i=1;i<=n;i++){
            scanf("%lld",&v[i]);
            if(i>=m)s=max(s,v[i-m]);
            v[i]+=v[i-1];
            if(i>=m)dp[i][1]=v[i]-s;
            else dp[i][1]=(long long)1e18;
            dp[i][1]=min(dp[i][1],dp[i-1][1]);
        }
        for(i=2;i<=k;i++){
            s=-(long long)1e18;
            for(j=0;j<m*i+i-1;j++)dp[j][i%2]=(long long)1e18;
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
