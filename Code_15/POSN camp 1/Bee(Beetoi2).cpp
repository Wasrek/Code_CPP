/*
    TASK:Bee(Beetoi2)
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[30][5];
int main()
{
    int n,i,j;
    dp[0][0]=dp[0][1]=1;
    for(i=1;i<=24;i++){
        dp[i][1]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
        dp[i][0]=dp[i-1][0];
        dp[i][2]=dp[i-1][1];
    }
    while(1){
        scanf("%d",&n);
        if(n==-1)return 0;
        printf("%d %d\n",dp[n][1],dp[n][2]+dp[n][1]+dp[n][0]);
    }
    return 0;
}
