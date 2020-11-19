/*
    TASK:RT_Almost Coin Change
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[2000010];
int main()
{
    int n,m,k,v;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m+k;i++)dp[i]=1<<30;
    for(int i=1;i<=n;i++){
        scanf("%d",&v);
        for(int j=v;j<=m+k;j++){
            dp[j]=min(dp[j-v]+1,dp[j]);
        }
    }
    int mi=1<<30,ans;
    for(int i=m;i<=m+k;i++){
        if(dp[i]<mi){
            mi=dp[i];
            ans=i-m;
        }
    }
    if(mi!=1<<30){
        printf("%d\n%d\n",mi,ans);
        return 0;
    }
    printf("-1\n");
    return 0;
}