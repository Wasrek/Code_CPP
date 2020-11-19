#include<bits/stdc++.h>
using namespace std;
const int N=15;
long long mask[1<<12],dp[1<<12];
int main(){
    int q,n,i,j,m,a,b;
    scanf(" %d",&q);
    while(q--){
        scanf(" %d %d",&n,&m);
        long long mirror=(1ll<<m)-1;
        for(i=0;i<n;i++){
            scanf(" %d",&a);
            for(j=0;j<a;j++) scanf(" %d",&b),b--,mask[1<<i]|=(1ll<<b);
        }
        for(i=1;i<(1<<n);i++){
            if(__builtin_popcount(i)==1) continue;
            for(j=1;j<i;j++){
                if((j&i)!=j) continue;
                dp[i]=max(dp[i],dp[j]+dp[i^j]+((mirror^mask[j])&mask[i^j]));
                mask[i]=mask[j]^mask[i^j];
            }
        }
//        for(i=1;i<(1<<n);i++) printf("%lld\n",dp[i]);
        printf("%lld\n",dp[(1<<n)-1]);
        memset(dp,0,sizeof dp);
        memset(mask,0,sizeof mask);
    }
    return 0;
}
