/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[5050],b[5050],dp[5050][5050];
int main()
{
    int n,now,idxa=0,idxb=0,ans=2e9;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&now);
        if(now){
            a[++idxa]=i;
        }else b[++idxb]=i;
    }
    memset(dp,127,sizeof dp);
    for(int i=0;i<=idxb;i++) dp[0][i]=0;
    for(int i=1;i<=idxa;i++){
        for(int j=1;j<=idxb;j++){
            if(j>=i)dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+abs(a[i]-b[j]));
            else dp[i][j]=2e9;
        }
    }
    printf("%d\n",dp[idxa][idxb]);
    return 0;
}