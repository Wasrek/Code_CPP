/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long dp[5010][3];
char s[3][5010];
int main()
{
    int q,n;
    bool ch=0;
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d",&n);
        for(int i=0;i<2;i++){
            scanf(" %s",s[i]+1);
        }
        dp[0][0]=dp[0][1]=1;
        ch=0;
        for(int i=1;i<=n;i++){
            if(s[0][i]=='.' && s[1][i]=='.'){
                dp[i][0]=(dp[i-1][0]+dp[i-1][1])%MOD;
                dp[i][1]=dp[i][0];
            }else if(s[0][i]=='.' && s[1][i]=='#'){
                dp[i][0]=dp[i-1][0];
                dp[i][1]=0;
            }else if(s[0][i]=='#' && s[1][i]=='.'){
                dp[i][1]=dp[i-1][1];
                dp[i][0]=0;
            }else{
                ch=1;
                break;
            }
        }
        if(ch) printf("0\n");
        else printf("%lld\n",(dp[n][0]+dp[n][1])%MOD);
    }
    return 0;
}