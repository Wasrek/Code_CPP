/*
    TASK:BUU Puzzle
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int s[13]={0,1,2,4,5,8,9,10,16,17,18,20,21};
int dp[15][50010],a[5][50010],ans=0;
int main(){
    int q,i,j,k,sum,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=0;i<5;i++)
            for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
        for(j=0;j<n;j++){
            for(i=0;i<13;i++){
                for(k=0,sum=0;k<5;k++)
                    if(s[i]&(1<<k))
                    sum+=a[k][j];
                for(k=0;k<13;k++)
                    if((s[i]&s[k])==0)
                    dp[i][j+1]=max(dp[i][j+1],dp[k][j]+sum);
            }
        }
        for(i=0;i<13;i++)
            ans=max(ans,dp[i][n]);
        printf("%d\n",ans);
        ans=0;
        memset(dp,0,sizeof dp);
    }
    return 0;
}
