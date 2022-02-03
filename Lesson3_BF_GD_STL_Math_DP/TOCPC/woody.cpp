/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long x,y,c;
};
A a[1010];
long long dp[510][510];
int main()
{
    long long n,x,y,sx,sy,sc;
    sx=sy=sc=0;
    scanf("%lld %lld %lld",&n,&x,&y);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld %lld",&a[i].x,&a[i].y,&a[i].c);
        sx+=a[i].x;
        sy+=a[i].y;
        sc+=a[i].c;
    }
    if(sx<x || sy<y){
        printf("-1\n");
        return 0;
    }
    long long mi=sc+100,i,j,k;
    for(i=0;i<=x;i++){
        for(j=0;j<=y;j++){
             dp[i][j]=sc+100;
        }
    }
    dp[0][0]=0;
    for(k=1;k<=n;k++){
        for(i=x;i>=0;i--){
            for(j=y;j>=0;j--){
                if(dp[i][j]!=sc+100){
                    dp[min(x,i+a[k].x)][min(y,j+a[k].y)]=min(dp[min(x,i+a[k].x)][min(y,j+a[k].y)],dp[i][j]+a[k].c);
                    if(i+a[k].x>=x && j+a[k].y>=y) mi=min(mi,dp[min(x,i+a[k].x)][min(y,j+a[k].y)]);
                }
            }
        }
    }
    printf("%lld\n",mi);
    return 0;
}