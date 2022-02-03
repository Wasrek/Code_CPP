/*
    TASK:A-Point
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[800][800],qs[800];
long long th(int a,int c,int b){
    long long i=qs[c]-qs[a-1];
    long long j=qs[b]-qs[c];
    long long ma=max(i,j);
    long long mi=min(i,j);
    return mi*2+ma;
}
int main()
{
    int n;
    long long now;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&now);
        qs[i]=qs[i-1]+now;
    }
    for(int k=1;k<n;k++){
        for(int i=1;i<=n-k;i++){
            int j=i+k;
            for(int c=i;c<j;c++){
                // printf("%d %d %d %lld\n",i,c,j,th(i,c,j));
                dp[i][j]=max(dp[i][j],th(i,c,j)+dp[i][c]+dp[c+1][j]);
            }
            // printf("%d %d %lld\n",i,j,dp[i][j]);
        }
    }
    // printf("%lld\n",dp[2][4]);
    printf("%lld\n",dp[1][n]);
    return 0;
}