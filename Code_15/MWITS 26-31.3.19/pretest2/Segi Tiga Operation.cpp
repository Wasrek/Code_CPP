/*
    TASK:Segi Tiga Operation
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[300],dp[300][300][4];
int main(){
    int loop=20,n,len,i,j,k,s;
    while(loop--){
        scanf("%d %s",&n,a);
        len=strlen(a);
        for(i=0;i<len;i++){
            dp[i][i][a[i]-'0']=1;
        }
        for(s=1;s<=n;s++){
            for(i=0;i<=n-s;i++){
                j=s+i-1;
                for(k=i;k<j;k++){
                    if(dp[i][k][0] && dp[k+1][j][0])dp[i][j][2]=1;
                    if(dp[i][k][0] && dp[k+1][j][1])dp[i][j][1]=1;
                    if(dp[i][k][0] && dp[k+1][j][2])dp[i][j][0]=1;
                    if(dp[i][k][1] && dp[k+1][j][0])dp[i][j][2]=1;
                    if(dp[i][k][1] && dp[k+1][j][1])dp[i][j][1]=1;
                    if(dp[i][k][1] && dp[k+1][j][2])dp[i][j][1]=1;
                    if(dp[i][k][2] && dp[k+1][j][0])dp[i][j][1]=1;
                    if(dp[i][k][2] && dp[k+1][j][1])dp[i][j][2]=1;
                    if(dp[i][k][2] && dp[k+1][j][2])dp[i][j][1]=1;
                }
            }
        }
        if(dp[0][n-1][0])printf("yes\n");
            else printf("no\n");
        memset(dp,0,sizeof dp);
    }
}
