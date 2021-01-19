/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[3010],dp[3010][3];
int main()
{
    int n,k,mi,mi1,now,midx,mii;
    scanf("%d %d",&n,&k);
    if(k>n){ printf("0\n"); return 0;}
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[i][0]=2e9;
        mi=mi1=mii=2e9;
        for(int j=i-1;j>max(0,i-k);j--){
            if(j+1-k>0) now=dp[j+1-k][1];
            else now=0;
            if(a[j+1]+now<mi){
                mi=a[j+1]+now;
                mii=
            }
            mi=min(mi,a[j+1]+now);
            mii=min(mii,a[j+1]);
            if(a[j]<=mi1){
                mi1=a[j];
                midx=j;
            }
            dp[i][0]=min(dp[i][0],a[j]+mi);
            if()
            // if(j-k+1>0){
            //     dp[i][0]=min(dp[i][0],mii+a[j]+dp[j-k+1][1]);
            // }else dp[i][0]=min(dp[i][0],mii+a[j]);
        }
        if(mi1==2e9)mi1=0;
        if(i-k>0) dp[i][1]=dp[i-k][1];
        // if(midx-k+1>0) dp[i][1]=min(dp[i-k][1],dp[midx-k+1][1]);
        // printf("- %d %d %d %d %d\n",a[i],midx,mi1,midx-k+1,dp[i][1]); 
        dp[i][1]+=(a[i]+mi1);
        // printf("%d %d %d\n",a[i],dp[i][1],dp[i][0]);
    }
    printf("%d\n",min(dp[n][1],dp[n][0]));
    return 0;
}