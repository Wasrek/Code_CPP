/*
    TASK:Plate Sort 2
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long pc[110][110],dp[110],h[110],sum[110];
int main()
{
    pc[0][0]=1;
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            if(i-1>=0){
                pc[i][j]+=pc[i-1][j];
                pc[i][j]%=9871;
                if(j-1>=0){
                    pc[i][j]+=pc[i-1][j-1];
                }
                pc[i][j]%=9871;
            }
        }
    }
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            if(j*2==i){
                pc[i][j]/=2;
            }
        }
    }
    long long q,n,k,ans;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&n,&k);
        dp[0]=1;
        h[0]=1;
        ans=0;
        for(int i=k;i<=n;i++){
            for(int j=k;j<=n;j++){
                dp[j]+=dp[j-i];
                if(dp[j-i]){
                    if(j!=n && j-i==0) continue;
                    h[j]+=(pc[n][j-i])+sum[j-i];
                    sum[j]+=h[j-i];
                    sum[j]%=9871;
                    h[j]%=9871;
                    // printf("%d %d\n",j,j-i);
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     printf("%d ",dp[i]);
        // }
        // printf("\n");
        // for(int i=1;i<=n;i++){
        //     printf("%d ",sum[i]);
        // }
        // printf("\n");
        // for(int i=1;i<=n;i++){
        //     printf("%d ",h[i]);
        // }
        // printf("\n");
        printf("%lld\n",h[n]);
        // printf("%d\n",dp[n]);
        memset(dp,0,sizeof dp);
        memset(h,0,sizeof h);
        memset(sum,0,sizeof sum);
    }
    return 0;
}