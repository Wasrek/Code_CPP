/*
    TASK:peatt board
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int main()
{
    int n,m,a,b,c,d,k,i,j;
    scanf("%d %d %d",&m,&n,&k);
    while(k--)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        dp[b][a]++; dp[b][c+1]--;
        dp[d+1][a]--; dp[d+1][c+1]++;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            printf("%d",dp[i][j]%2);
        }
        printf("\n");
    }
    return 0;
}
