/*
    TASK:RT_Almost Coin Change
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[2000010];
int main(){
    int n,m,k,i,j,v,mi=1<<30,ans=0;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=m+k;i++)dp[i]=1<<30;
    for(i=0;i<n;i++){
        scanf("%d",&v);
        for(j=v;j<=m+k;j++)
            dp[j]=min(dp[j],dp[j-v]+1);
    }
    for(i=m;i<=m+k;i++){
        if(dp[i]<mi)
            mi=dp[i],ans=i-m;
    }
    if(mi==1<<30)printf("-1\n");
    else printf("%d\n%d\n",mi,ans);
    return 0;
}
