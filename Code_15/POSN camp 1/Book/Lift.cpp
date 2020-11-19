/*
    TASK:Lift
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[46000];
int main()
{
    int i,n,now,sum=0,Min=1<<30,ans1,ans2;
    scanf("%d",&n);
    dp[0]=1;
    while(n--){
        scanf("%d",&now);
        for(i=45001;i>=now;i--)
            if(dp[i-now]==1)
            dp[i]=1;
        sum+=now;
    }
    for(i=0;i<=sum;i++){
        if(dp[i]==1){
            if(abs(sum - 2*i) < Min){
                Min = abs(sum - 2*i);
                ans1 = i,ans2 = sum-i;
            }
        }
    }
    if(ans1>ans2) swap(ans1,ans2);
    printf("%d %d\n",ans1,ans2);
    return 0;
}
