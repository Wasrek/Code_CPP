/*
    TASK:NC_Decrease
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],dp[100010][3];
int main(){
    int q,n,i,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(i=2;i<=n;i++){
            dp[i][0]=max(dp[i-1][0]+abs(a[i]-a[i-1]),dp[i-1][1]+a[i]-1);
            dp[i][1]=max(dp[i-1][0]+a[i-1]-1,dp[i-1][1]);
        }
        ans=max(dp[n][0],dp[n][1]);
        printf("%d\n",ans);
    }
}
