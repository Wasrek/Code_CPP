/*
    TASK:Destruction
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[50010],dp[2][50010],qs[50010];
int main(){
    long long n,m,k,i,j,mi;
    scanf("%lld %lld %lld",&n,&k,&m);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        qs[i]=qs[i-1]+a[i];
    }
    for(i=1;i<=k;i++){
        mi=1e18;
        for(j=i*m+i-1;j<=n;j++){
            mi=min(mi,dp[(i-1)%2][max(j-m-1,0ll)]-qs[j-m]);
            dp[i%2][j]=qs[j]+mi;
            if(j!=i*m+i-1)dp[i%2][j]=min(dp[i%2][j],dp[i%2][j-1]);
        }
    }
    printf("%lld\n",qs[n]-dp[k%2][n]);
}
