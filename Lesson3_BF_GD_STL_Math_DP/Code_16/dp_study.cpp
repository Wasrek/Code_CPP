/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[10010],dp1[10010],dp2[10010],dp3[10010];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);

    dp[0]=1;
    for(int i=1;i<=k;i++){
        for(int j=i;j<=n;j++){
            dp[j]+=dp[j-i];
        }
    }// Knapsack RT_TOI48  Kuth Coin
    for(int i=1;i<=n;i++) printf("%d ",dp[i]);
    
    printf("\n");
    dp1[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i-j>=0)
            dp1[i]+=dp1[i-j];
        }
    }// Pots
    for(int i=1;i<=n;i++) printf("%d ",dp1[i]);
    
    printf("\n");
    dp2[0]=1;
    for(int i=1;i<=k;i++){
        for(int j=n;j>=1;j--){
            dp2[j]+=dp2[j-i];
        }
    }// Lift   Reap Plum Tree   Stair
    for(int i=1;i<=n;i++) printf("%d ",dp2[i]);

    printf("\n");
    dp3[0]=1;
    for(int i=n;i>=1;i--){
        for(int j=1;j<=k;j++){
            dp3[i]+=dp3[i-j];
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",dp3[i]);
    return 0;
}