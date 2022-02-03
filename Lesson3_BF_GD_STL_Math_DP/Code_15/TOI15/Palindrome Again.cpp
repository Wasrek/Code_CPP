/*
    TASK:Palindrome Again
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[5010],b[5010];
int dp[5010][5010];
int main(){
    int n,len,i,cou,j;
    scanf("%d",&n);
    scanf(" %s",a+1);
    len=strlen(a+1);
    cou=len;
    for(i=1;i<=len;i++){
        b[cou]=a[i];
        cou--;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else if(dp[i-1][j]>=dp[i][j-1])
                dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i][j-1];
        }
    }
    //printf("%d",dp[n][n]);
    printf("%d",n-dp[n][n]);
}
