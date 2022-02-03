/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[1010];
int dp[1010][5];
int main()
{
    int q,x,y,len,la;// x=cj y=jc
    scanf("%d",&q);
    for(int Q=1;Q<=q;Q++){
        memset(dp,0,sizeof dp);
        scanf("%d %d",&x,&y);
        scanf("%s",s+1);
        len=strlen(s+1);
        la=0;
        if(s[1]=='C') {dp[1][1]=0,dp[1][2]=2e9;}
        else {dp[1][1]=2e9,dp[1][2]=0;}
        if(s[1]=='?') dp[1][1]=dp[1][2]=0;
        // printf("%d %d\n",dp[1][1],dp[1][2]);
        for(int i=2;i<=len;i++){
            if(s[i]=='C'){
                dp[i][1]=min(dp[i-1][1],dp[i-1][2]+y);
                dp[i][2]=2e9;
            }
            if(s[i]=='J'){
                dp[i][2]=min(dp[i-1][2],dp[i-1][1]+x);
                dp[i][1]=2e9;
            }
            if(s[i]=='?'){
                dp[i][2]=min(dp[i-1][2],dp[i-1][1]+x);
                dp[i][1]=min(dp[i-1][1],dp[i-1][2]+y);
            }
            // printf("%d %d\n",dp[i][1],dp[i][2]);
        }
        printf("Case #%d: %d\n",Q,min(dp[len][1],dp[len][2]));
    }
    return 0;
}