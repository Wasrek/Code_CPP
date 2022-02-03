/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[5050],b[5050];
int dp[5050][5050];
int main()
{
    int n;
    scanf("%d",&n);
    scanf(" %s",a+1);
    for(int i=1,j=n;i<=n;i++) b[j--]=a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
        }
    }
    // printf("%d\n",dp[n][n]);
    printf("%d\n",n-dp[n][n]);
    return 0;
}