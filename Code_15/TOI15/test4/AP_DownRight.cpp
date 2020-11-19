/*
    TASK:AP_DownRight
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1010][1010],dp[1010][1010];
int fin(int i,int j){
    return max(dp[i-2][j],max(dp[i][j-2],dp[i-1][j-1]));
}
int main(){
    long long q,r,c,i,j,all;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&r,&c);
        for(i=3;i<=r+2;i++){
            for(j=3;j<=c+2;j++){
                scanf("%lld",&a[i][j]);
            }
        }
        for(i=3;i<=r+2;i++){
            for(j=3;j<=c+2;j++){
                dp[i][j]=fin(i,j)+a[i][j];//1 เว้น 1
                dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
                dp[i][j]=max(dp[i][j],max(a[i][j]+a[i-1][j]+fin(i-1,j),a[i][j]+a[i][j-1]+fin(i,j-1)));
            }
        }
        printf("%lld\n",dp[r+2][c+2]);
        memset(dp,0,sizeof dp);
    }
    return 0;
}
/*
1
5 5
1 1 3 2 1
1 1 2 9 1
1 1 1 9 1
1 1 1 1 9
1 1 1 1 1
*/
