/*
    TASK:Pascal Triangle
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[10100][10100];
int main()
{

    int i,j;
    int n;
    scanf("%d",&n);
    n+=2;
    dp[1][1]=1;
    dp[1][2]=1;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%55555;
        }
    }
    for(j=2; j<=n; j++)
    {
        printf("%d ",dp[n][j]);
    }
}
