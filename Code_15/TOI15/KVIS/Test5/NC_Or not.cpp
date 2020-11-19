/*
    TASK:NC_Or not
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[1000100];
int dp[2000100];
int main(){
    int n,i,ans=0,sum=0;
    scanf("%d",&n);
    scanf(" %s",s);
    dp[n]=1;
    for(i=0;i<n;i++){
        if(s[i]=='1')sum++;
        else sum--;
        ans+=dp[sum+n];
        dp[sum+n]++;
        ans%=10007;
    }
    printf("%d\n",ans);
}
