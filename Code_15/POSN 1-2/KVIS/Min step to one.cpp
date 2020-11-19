/*
    TASK:Min step to one
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000010];
int main()
{
    int q,i,z;
    scanf("%d",&q);
    dp[1] = 0;
    dp[2] = dp[3] = 1;
    for(i=4;i<=1000010;i++){
        dp[i]=dp[i-1]+1;
        if(i%2==0)dp[i]=min(dp[i],dp[i/2]+1);
        if(i%3==0)dp[i]=min(dp[i],dp[i/3]+1);
    }
    while(q--){
        scanf("%d",&z);
        printf("%d\n",dp[z]);
    }

    return 0;
}
