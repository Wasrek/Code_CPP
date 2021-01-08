/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010];
int dp[1010][1010];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %c",&a[i]);
        if(a[i]==a[i-1]) dp[i-1][i]=1;
    }
    for(int k=3;k<=n;k++){
        for(int s=1;s<=n-k+1;s++){
            int e=s+k-1;
            if(a[s]==a[e]) dp[s][e]=max(dp[s][e],1+dp[s+1][e-1]);
            for(int p=s;p<e;p++){
                dp[s][e]=max(dp[s][e],dp[s][p]+dp[p+1][e]);
            }
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}