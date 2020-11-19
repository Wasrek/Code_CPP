#include<bits/stdc++.h>
using namespace std;
int dp[105][105][105][2],n,m,ka,kb;
int play(int a,int b,int c,int st)
{
    int sum=0;
    if(dp[a][b][c][st]!=-1)
        return dp[a][b][c][st];
    if(a==n&&b==m)
    {
        return 1;
    }
    if(!st){
        if(a<n&&c<ka){
            sum+=play(a+1,b,c+1,0);
        }
        if(b<m){
            sum+=play(a,b+1,1,1);
        }
        sum%=1000000007;
    }
    if(st){
        if(b<m&&c<kb){
            sum+=play(a,b+1,c+1,1);
        }
        if(a<n){
            sum+=play(a+1,b,1,0);
        }
        sum%=1000000007;
    }
    return dp[a][b][c][st]=sum;
}
int main()
{
    scanf("%d %d %d %d",&n,&m,&ka,&kb);
    memset(dp,-1,sizeof dp);
    printf("%d",play(0,0,0,0));
    return 0;
}
