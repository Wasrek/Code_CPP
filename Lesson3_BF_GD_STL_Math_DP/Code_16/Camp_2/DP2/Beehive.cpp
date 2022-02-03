/*
    TASK:Beehive
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[1010][1010],sa[1010][1010];
int main()
{
    int n,m;
    long long ma=0,ans=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&dp[i][j]);
            if(i%2==0){
            if(dp[i-1][j]==dp[i-1][j+1]){
                dp[i][j]+=dp[i-1][j];
                sa[i][j]=sa[i-1][j]+sa[i-1][j+1];
            }else if(dp[i-1][j]>dp[i-1][j+1]){
                dp[i][j]+=dp[i-1][j];
                sa[i][j]=sa[i-1][j];
            }else {
                dp[i][j]+=dp[i-1][j+1];
                sa[i][j]=sa[i-1][j+1];
            }
            }
            else{
            if(dp[i-1][j]==dp[i-1][j-1]){
                dp[i][j]+=dp[i-1][j];
                sa[i][j]=sa[i-1][j]+sa[i-1][j-1];
            }else if(dp[i-1][j]>dp[i-1][j-1]){
                dp[i][j]+=dp[i-1][j];
                sa[i][j]=sa[i-1][j];
            }else {
                dp[i][j]+=dp[i-1][j-1];
                sa[i][j]=sa[i-1][j-1];
            }
            }
            if(i==1) sa[i][j]=1;
            if(i==n && dp[i][j]>ma){
                ma=dp[i][j];
                ans=sa[i][j];
            }else
            if(i==n && ma==dp[i][j]){ans+=sa[i][j];}
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%lld %lld\n",ma,ans);
    return 0;
}