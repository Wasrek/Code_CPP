/*
    TASK:Coin change min
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000100];
int a[11];
int main()
{
    int c,m,now;
    scanf("%d %d",&c,&m);
    for(int i=1;i<=m;i++){
        dp[i]=1e9;
    }
    for(int i=1;i<=c;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=c;j++){
            if(a[j]>i)continue;
            dp[i]=min(dp[i],dp[i-a[j]]+1);
        }
    }
    if(dp[m]==1e9)dp[m]=0;
    printf("%d\n",dp[m]);
    return 0;
}