/*
    TASK:Swift Day II
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[30],dp[2500];
int main(){
    long long n,m,b,t,i,now,j,ans=1<<30,aa;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++){
        scanf("%lld",&b);
        aa = 0;
        while(b--){
            scanf("%lld",&t);
            aa |= (1<<(t-1));
        }
        a[i] = aa;
    }
    for(i=0;i<(1<<m);i++){
        dp[i] = 1<<30;
    }
    dp[0]=0;
    long long k ;
    for(j=1;j<=n;j++){
        for(i=0;i<(1<<m);i++){
            k = a[j];
            k |= i;
            if(dp[i]+1 < dp[k])
                dp[k] = dp[i]+1;
        }
    }
    printf("%lld\n",dp[(1<<m)-1]);
}
