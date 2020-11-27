/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[510][510];
int main()
{
    memset(dp,-1,sizeof dp);
    dp[0][0]=0;
    for(int a=0;a<=40;a++){
        for(int b=0;b<=40;b++){
            if(!a && !b) continue;
            for(int i=500-a;i>=0;i--){
                for(int j=500-b;j>=0;j--){
                    if(dp[i][j]>=0) dp[i+a][j+b]=max(dp[i+a][j+b],dp[i][j]+1);
                }
            }
        }
    }
    int q,a,b;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&b);
        printf("%lld\n",dp[a][b]);
    }
    return 0;
}