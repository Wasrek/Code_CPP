/*
    TASK:PT_Box Stack
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010],w[1010],s[1010];
int main(){
    int q,n,i,j,ma;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        dp[0]=1<<30;
        ma=0;
        for(i=1;i<=n;i++){
            scanf("%d %d",&w[i],&s[i]);
            for(j=i;j>=0;j--){
                if(w[i]<=dp[j-1]){
                    dp[j]=max(dp[j],min(s[i],dp[j-1]-w[i]));
                    ma=max(j,ma);
                }
            }
        }
        printf("%d\n",ma);
        memset(dp,0,sizeof dp);
    }
}
