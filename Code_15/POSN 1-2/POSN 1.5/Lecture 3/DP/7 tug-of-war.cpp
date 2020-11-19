/*
    TASK:tug-of-war
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000100],a[1000100];
int main()
{
    int n,i,num,last;
    scanf("%d %d",&n,&last);
    for(i=1;i<n;i++){
        scanf("%d",&num);
        a[i]=num-last,last=num;
    }
    dp[1]=a[1];
    for(i=2;i<n;i++)
        dp[i]=max(dp[i-1],dp[i-2]+a[i]);
    printf("%d\n",max(dp[n-1],dp[n-2]));

    return 0;
}
