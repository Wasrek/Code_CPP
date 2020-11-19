/*
    TASK:Segi Tiga Operation
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int len,dp[300][300][5];
char s[300];
int main()
{
    for(int q=1;q<=20;q++){
        scanf("%d",&len);
        scanf(" %s",s+1);
        for(int i=1;i<=len;i++){
            dp[i][i][s[i]-'0']=1;
        }
        for(int k=2;k<=len;k++){
            for(int i=1;i<=len-k+1;i++){
                int j=i+k-1;
                for(int l=i;l<j;l++){
                    if(dp[i][l][0] && dp[l+1][j][2]) dp[i][j][0]=1;
                    if((dp[i][l][0] && dp[l+1][j][1]) || (dp[i][l][1] && dp[l+1][j][1]) || (dp[i][l][1] && dp[l+1][j][2]) || (dp[i][l][2] && dp[l+1][j][0]) || (dp[i][l][2] && dp[l+1][j][2]))
                    dp[i][j][1]=1;
                    if((dp[i][l][0] && dp[l+1][j][0]) || (dp[i][l][1] && dp[l+1][j][0]) || (dp[i][l][2] && dp[l+1][j][1])) dp[i][j][2]=1;
                    
                    // printf("%d %d %d %d %d %d\n",i,j,l,dp[i][j][0],dp[i][j][1],dp[i][j][2]);
                }
            }
        }
        // printf("%d %d %d",dp[1][2][0],dp[2][3][1],dp[3][4][1]);
        if(dp[1][len][0]) printf("yes\n");
        else printf("no\n");
        memset(dp,0,sizeof dp);
    }
    return 0;
}