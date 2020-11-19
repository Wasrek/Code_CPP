/*
    TASK:Pairs of Four
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010];
int dp[1010][1010];
int play(int l,int r){
    if(dp[l][r]!=-1) return dp[l][r];
    if(l>=r)         return 0;
    int cou=0;
    if(a[l]==a[r]){
        cou=play(l+1,r-1)+1;
    }
    for(int k=l;k<r;k++){
        cou=max(cou,play(l,k)+play(k+1,r));
    }
    return dp[l][r]=cou;
}
int main()
{
    int n,ans;
    scanf("%d",&n);
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=n;i++){
        scanf(" %c",&a[i]);
        dp[i][i]=0;
    }
    ans=play(1,n);
    printf("%d\n",ans);
    return 0;
}