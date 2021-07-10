#include<bits/stdc++.h>
using namespace std;
char a[2][5010];
int dp[2][5010];
int main(){
    int i,j,n,q,M=1000000007,ch=0;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        scanf(" %s",a[0]+1);
        scanf(" %s",a[1]+1);
        a[0][0]=a[1][0]='.';
        memset(dp,0,sizeof dp);
        dp[0][0]=dp[1][0]=1;
        ch=0;
        for(i=1;i<=n;i++){
            if(a[0][i]=='#'&&a[1][i]=='#'){
                ch=1;
                break;
            }
            if(a[0][i-1]=='#'&&a[1][i-1]=='.'){
                if(a[1][i]=='#'){
                    ch=1;
                    break;
                }else{
                    if(a[0][i]=='.') dp[0][i]=dp[1][i-1];
                    if(a[1][i]=='.') dp[1][i]=dp[1][i-1];
                }
            }
            else if(a[0][i-1]=='.'&&a[1][i-1]=='#'){
                if(a[0][i]=='#'){
                    ch=1;
                    break;
                }else{
                    if(a[0][i]=='.') dp[0][i]=dp[0][i-1];
                    if(a[1][i]=='.') dp[1][i]=dp[0][i-1];
                }
            }
            else{
                if(a[0][i]=='.'&&a[1][i]=='.') dp[0][i]=dp[1][i]=(2*dp[0][i-1])%M;
                else{
                    if(a[0][i]=='.') dp[0][i]=dp[1][i-1];
                    if(a[1][i]=='.') dp[1][i]=dp[1][i-1];
                }
            }
        }
        if(ch==1) printf("0\n");
        else printf("%d\n",(dp[0][n]+dp[1][n])%M);
    }
return 0;
}
