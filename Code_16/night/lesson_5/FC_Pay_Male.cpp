/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 100003
int dp[110][110][110][4];
int main()
{
    dp[1][0][0][0]=dp[0][1][0][1]=dp[0][0][1][2]=1;
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            for(int k=0;k<=100;k++){
                if(i==0 && j==0 && k==0) continue;
                if(i-1>=0 && !dp[i][j][k][0]) dp[i][j][k][0]=(dp[i-1][j][k][1]+dp[i-1][j][k][2])%mod;
                if(j-1>=0 && !dp[i][j][k][1]) dp[i][j][k][1]=(dp[i][j-1][k][0]+dp[i][j-1][k][2])%mod;
                if(k-1>=0 && !dp[i][j][k][2]) dp[i][j][k][2]=(dp[i][j][k-1][0]+dp[i][j][k-1][1])%mod;
            }
        }
    }
    int q,a,b,c;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&a,&b,&c);
        printf("%d\n",(((dp[a][b][c][0]+dp[a][b][c][1])%mod)+dp[a][b][c][2])%mod);
    }
    return 0;
}