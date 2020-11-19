/*
    TASK:RT_Econ way
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[220][220],a[220][220];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]+a[i][j]);
        }
    }
    printf("%d\n",dp[n][n]);
    return 0;
}