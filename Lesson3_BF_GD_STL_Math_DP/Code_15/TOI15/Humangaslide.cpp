/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int pre[500003][26];
int dp[605][605];
char a[500003];
char b[610];
int main()
{
    int n,q,i,j,lenb,now,cou,Max,temp,temp2;
    scanf("%d %d",&n,&q);
    scanf(" %s",a+1);
    for(i=0;i<=n;i++){
        for(j=0;j<26;j++)pre[i][j]=1<<30;
    }
    for(i=n-1;i>=0;i--){
        pre[i][a[i+1]-'A']=i+1;
        for(j=0;j<26;j++){
            pre[i][j]=min(pre[i][j],pre[i+1][j]);
//            printf("%d %d %d\n",i,j,pre[i][j]);
        }
    }
    while(q--){
        scanf(" %s",b+1);
        lenb=strlen(b+1);
        memset(dp,127,sizeof dp);
        dp[0][0]=Max=0;
        for(i=1;i<=lenb;i++){
            for(int j=0;j<=i;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(dp[i-1][j-1]<=n) dp[i][j] = min(dp[i][j], pre[dp[i-1][j-1]][b[i]-'A']);
                if(dp[i][j]<=n) Max=max(Max,j);
    //                printf("%d %d %d\n",i,j,dp[i][j]);
            }
        }
        printf("%d\n",Max);
    }
    return 0;
}
/*
5 2
ABCDE
CD
BBABBC
*/
