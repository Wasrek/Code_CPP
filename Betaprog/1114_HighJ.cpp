/*
    TASK: HighJump
    LANG: CPP
    AUTHOR: WasreK
    ALGO: DP
    TYPE: BATCH
    SCORE: 100
*/
#include<bits/stdc++.h>
using namespace std;
int a[610][610];
int dp[610];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++){
        for(int j=1;j<=2*n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=3;i<=2*n;i++){
        dp[i]=2e9;
        for(int j=2;j<i;j++){
            dp[i]=min(a[i][j]+dp[j],dp[i]);
        }
    }
    printf("%d\n",dp[n*2]);
    return 0;
}