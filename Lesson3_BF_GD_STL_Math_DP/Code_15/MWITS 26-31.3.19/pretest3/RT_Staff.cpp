/*
    TASK:RT_Staff
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100],dp[2000100];
int main(){
    int q,n,i;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)dp[i]=1<<30;
        dp[1]=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            //if(i==1){dp[1]=0;dp[i+a[i]]=dp[i-1]+1;continue;}
            dp[i]=min(dp[i],dp[i-1]+1);
            dp[i+a[i]]=min(dp[i]+1,dp[i+a[i]]);
        }
//        for(i=1;i<=n;i++)printf("%d ",dp[i]);
//        printf("\n");
        printf("%d\n",dp[n]);
    }
}
/*
2
5
2 3 3 1 1
6
3 2 2 3 2 5
*/
