/*
    TASK:FC_Golden Age
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int n,a[5100],dp[5100][110];
int play(int u,int k){
    if(u>n || k==0) return 0;
    if(k==0) return 0;
    if(dp[u][k]!=-1) return dp[u][k];
    int i,ans=0;
    for(i=0;k-i-1>=0;i++)
        ans=max(ans,a[u]+play(2*u,i)+play(2*u+1,k-i-1));
    return dp[u][k]=ans;
}
int main(){
    int i,k,ans=0;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    memset(dp,-1,sizeof dp);
    for(i=1;i<=n;i++)
        ans=max(ans,play(i,k));
    printf("%d\n",ans);
    return 0;
}
