/*
    TASK:NC_Combi
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int n,m,ka,kb,dp[110][110][110][110];
int play(int i,int j,int k,int l){
    if(i>n || j>m || k>ka || l>kb) return 0;
    if(dp[i][j][k][l]!=-1) return dp[i][j][k][l];
    if(i==n && j==m) return 1;
    int sum = 0;
    sum+=play(i+1,j,k+1,0)%MOD;
    sum+=play(i,j+1,0,l+1)%MOD;
    return dp[i][j][k][l]=sum % MOD;
}
int main()
{
    scanf("%d %d %d %d",&n,&m,&ka,&kb);
    memset(dp,-1,sizeof dp);
    printf("%d\n",play(0,0,0,0));
    return 0;
}