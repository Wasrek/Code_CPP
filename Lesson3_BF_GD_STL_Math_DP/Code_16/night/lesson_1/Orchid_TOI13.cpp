/*
    TASK:Orchid TOI13
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000100];
int main()
{
    int n,cnt=0,idx,now;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&now);
        idx=upper_bound(dp,dp+cnt,now)-dp;
        // printf("%d\n",idx);
        if(idx==cnt)cnt++;
        dp[idx]=now;
    }
    printf("%d",n-cnt);
    return 0;
}