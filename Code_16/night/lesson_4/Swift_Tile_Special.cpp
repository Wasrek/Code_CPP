/*
    TASK:Swift Tile Special
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 9241
int dp[110][110];
int main()
{
    dp[0][0]=1;
    for(int k=0;k<=100;k++){
        dp[0][k]=1;
        for(int i=1;i<=100;i++){
            dp[i][k]+=dp[i-1][k]%mod;
            dp[i][k]%=mod;
            if(i>=2){
                dp[i][k]+=dp[i-2][k]%mod;
                dp[i][k]%=mod;
            }
            if(!k || i<2) continue;
            dp[i][k]+=dp[i-2][k-1]%mod;
            if(k>=2 && i>=3){
                for(int j=3;j<=i;j++){
                    dp[i][k]+=((dp[i-j][k-2]%mod)*2)%mod;
                    dp[i][k]%=mod;
                }
            }
        }
    }
    int q,a,b;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&b);
        printf("%d\n",dp[a][b]%mod);
    }
    return 0;
}