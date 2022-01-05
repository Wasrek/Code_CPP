/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010],la[1000010],dp[1000010],cnt[1000010];
int main()
{
    int n,k,midp=0;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+1;
        if(cnt[a[i]]==1) dp[i]--;
        if(!la[a[i]]){
            la[a[i]]=i;
        }else{
            // printf("%d ",la[a[i]]);
            // printf("%d %d ",dp[la[a[i]]-1],i-la[a[i]]-1);
            dp[i]=min(dp[i],dp[la[a[i]]-1]+i-la[a[i]]-1);
        }
        // printf("%d\n",dp[i]);
    }
    printf("%d\n",dp[n]);
    return 0;
}