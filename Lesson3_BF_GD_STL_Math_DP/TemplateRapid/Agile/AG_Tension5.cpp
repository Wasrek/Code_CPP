#include<bits/stdc++.h>
using namespace std;
int a[300010],dp[2][300010];
int main(){
    int n,i,ans=-1,j,q;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        ans=-1;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            ans=max(ans,a[i]);
        }
        for(i=1;i<=n+1;i++) dp[0][i]=dp[1][i]=1e9;
        for(j=0;j<=70;j++){
            for(i=1;i<=n+1;i++) dp[j%2][i]=1e9;
            for(i=1;i<=n;i++){
                if(dp[1-j%2][i]!=1e9) dp[j%2][i]=dp[1-j%2][dp[1-j%2][i]];
                else dp[j%2][i]=1e9;
            }
            for(i=1;i<=n;i++){
                if(a[i]==j) dp[j%2][i]=i+1;
            }
            for(i=1;i<=n;i++){
                if(dp[j%2][i]<=n+1) ans=j;
            }
        }
        printf("%d\n",ans);
    }
return 0;
}
