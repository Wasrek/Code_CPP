/*
    TASK:RT_Econ way
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[300][300],a[300][300];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]+a[i][j]);
    }
    printf("%d\n",dp[n][n]);
    return 0;
}
/*
3
1 20 10
5 30 50
20 15 10
*/
