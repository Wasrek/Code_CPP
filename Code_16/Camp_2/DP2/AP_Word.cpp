/*
    TASK:AP_Word
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[5010],b[5010];
int dp[5010][5010];
int main()
{
    int q,n,m;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        scanf(" %s",a+1);
        scanf(" %s",b+1);
        for(int i=1;i<=n;i++){
            dp[i][0]=dp[i-1][0]+1;
        }
        for(int i=1;i<=m;i++){
            dp[0][i]=dp[0][i-1]+1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                // printf("%d ",dp[i][j]);
            }
            // printf("\n");
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}