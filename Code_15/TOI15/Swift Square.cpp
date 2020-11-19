/*
    TASK:Swift Square
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[10010][101],a[110],n;
int play(int b,int st){
    if(dp[b][st]!=-1)return dp[b][st];
    if(b==0 && st==n+1)return 0;
    if(b==0 || st==n+1)return 1e9;
    int i;
    for(i=1;i<=100;i++){
        if(i*i>b)continue;
        if(dp[b][st]==-1){
            dp[b][st]=play(b-i*i,st+1)+(a[st]-i)*(a[st]-i);
        }else
        dp[b][st]=min(dp[b][st],play(b-i*i,st+1)+(a[st]-i)*(a[st]-i));
    }
    return dp[b][st];
}
int main(){
    int i,j,k,b,ans;
    scanf("%d %d",&n,&b);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    memset(dp,-1,sizeof dp);
    ans=play(b,1);
    if(ans>=1e9)printf("-1\n");
    else
    printf("%d\n",ans);
    return 0;
}
