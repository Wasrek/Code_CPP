/*
    TASK:Orchid TOI13
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000100];
int main(){
    int n,i,cnt=0,idx,m;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&m);
        idx=upper_bound(dp,dp+cnt,m)-dp;
        if(idx==cnt)cnt++;
        dp[idx]=m;
    }
    //for(i=0;i<cnt;i++)printf("%d ",dp[i]);
    printf("%d\n",n-cnt);
}
