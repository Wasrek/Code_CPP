/*
    TASK:FC_Plate Pick
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[205][205][205];
long long plate[3][205];
long long play(long long a,long long b,long long c,long long turn){
    if(!a && !b && !c)return dp[a][b][c]=0;
    if(dp[a][b][c]!=-1) return dp[a][b][c];
    if(!turn){
        long long ma=0;
        if(a) ma=max(ma,plate[0][a]+play(a-1,b,c,turn^1));
        if(b) ma=max(ma,plate[1][b]+play(a,b-1,c,turn^1));
        if(c) ma=max(ma,plate[2][c]+play(a,b,c-1,turn^1));
        return dp[a][b][c]=ma;
    }
    long long mi=8e15;
    if(a) mi=min(mi,play(a-1,b,c,turn^1));
    if(b) mi=min(mi,play(a,b-1,c,turn^1));
    if(c) mi=min(mi,play(a,b,c-1,turn^1));
    return dp[a][b][c]=mi;
}
int main(){
    memset(dp,-1,sizeof dp);
    long long n,sum=0;
    scanf("%lld",&n);
    for(long long i=0;i<3;i++)for(long long j=1;j<=n;j++)scanf("%lld",&plate[i][j]),sum+=plate[i][j];
    printf("%lld %lld\n",play(n,n,n,0),sum-play(n,n,n,0));
    return 0;
}
