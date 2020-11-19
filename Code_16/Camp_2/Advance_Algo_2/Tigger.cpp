/*
    TASK:Tigger
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010],dp[1010][1010],n;
int play(int now,int last){
    if(now<1 || now>n) return 1e6;
    if(dp[now][last]!=-1) return dp[now][last];
    if(now==n) return a[now];
    dp[now][last]=a[now]+min(play(now+last+1,last+1),play(now-last,last));
    return dp[now][last];
}
int main()
{
    int ans;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    memset(dp,-1,sizeof dp);
    ans=play(2,1); 
    printf("%d\n",ans);
    return 0;
}