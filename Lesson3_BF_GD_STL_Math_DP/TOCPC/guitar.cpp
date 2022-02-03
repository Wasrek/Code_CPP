/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[330][330],ord[330],dp[330][330];
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&ord[i]);
    }
    for(int i=1;i<=m+1;i++){
        for(int j=0;j<=k;j++){
            if(j<i) dp[i][j]=LLONG_MAX;
        }    
    }
    for(int i=1;i<=m+1;i++){
        for(int j=0;j<=min(i,k);j++){
            for(int l=0;l<=j;l++){
                // printf("%d\n",dp[i][j]);
                dp[i][j]=min(dp[i][j],dp[i-l-1][j-l]+a[ord[i-l-1]][ord[i]]);
                // printf("%d %d %d %d %d\n",i,j,l,dp[i-l-1][j-l],dp[i][j]);
            }
        }
    }
    printf("%lld\n",dp[m+1][k]);
    return 0;
}