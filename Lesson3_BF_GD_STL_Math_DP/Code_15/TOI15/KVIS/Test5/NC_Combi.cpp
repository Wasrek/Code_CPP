/*
    TASK:NC_Combi
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[110][110][110][3],n,m,ka,kb,ans;
long long play(long long a,long long b,long long c,long long w){
    if(dp[a][b][c][w]!=-1)return dp[a][b][c][w];
    if(a==n && b==m)return 1;
    long long sum=0;
    if(w==1){
        if(a<n&&c<ka){
            sum+=play(a+1,b,c+1,1);
        }
        if(b<m){
            sum+=play(a,b+1,1,2);
        }
        sum%=1000000007;
    }
    if(w==2){
        if(b<m&&c<kb){
            sum+=play(a,b+1,c+1,2);
        }
        if(a<n){
            sum+=play(a+1,b,1,1);
        }
        sum%=1000000007;
    }
    return dp[a][b][c][w]=sum;
}
int main(){
    memset(dp,-1,sizeof dp);
    scanf("%lld %lld %lld %lld",&n,&m,&ka,&kb);
    ans=play(0,0,0,1);
    printf("%lld",ans);
}
