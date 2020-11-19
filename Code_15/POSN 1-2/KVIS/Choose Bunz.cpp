/*
    TASK:Choose Bunz
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[10100][10100];
int main()
{
    int n,r,k,i,j;
    scanf("%d %d %d",&n,&r,&k);n+=2,r+=2;
    if(n<2){printf("%d",1%k);return 0;}
    dp[1][1]=1;dp[1][2]=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%k;
            //printf("%d ",dp[i][j]);
        }
        //printf("\n");
    }
    printf("%d",dp[n][r]%k);

    return 0;
}
