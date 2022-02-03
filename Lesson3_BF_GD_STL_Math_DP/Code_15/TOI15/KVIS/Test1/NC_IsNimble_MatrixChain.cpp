/*
    TASK:NC_IsNimble
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[41][41][41][41],a[41][41],b[41][41][41][41];
long long play(long long i,long long j,long long k,long long l){
    if(dp[i][j][k][l]!=-1)return dp[i][j][k][l];
    if(i==k && j==l)return 0;
    long long x,minn=1e9;
    for(x=i;x<k;x++){
        minn=min(minn,play(i,j,x,l)+play(x+1,j,k,l)+b[i][j][x][l]+b[x+1][j][k][l]);
    }
    for(x=j;x<l;x++){
        minn=min(minn,play(i,j,k,x)+play(i,x+1,k,l)+b[i][j][k][x]+b[i][x+1][k][l]);
    }
    return dp[i][j][k][l]=minn;
}
int main(){
    long long i,j,k,l,r,s,n,m;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            for(k=1;k<=n;k++){
                for(l=1;l<=m;l++){
                    b[i][j][k][l]=1;
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            for(k=1;k<=n;k++){
                for(l=1;l<=m;l++){
                    for(r=i;r<=k;r++){
                        for(s=j;s<=l;s++){
                            b[i][j][k][l]*=a[r][s];
                        }
                    }
                }
            }
        }
    }
    memset(dp,-1,sizeof dp);
    printf("%lld",play(1,1,n,m));
    return 0;
}
