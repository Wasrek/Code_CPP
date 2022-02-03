/*
    TASK:Orchid TOI13
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100],dp[1000100];
int main(){
    int n,i,idx,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        idx=upper_bound(dp,dp+cnt,a[i])-dp;
        if(idx==cnt)cnt++;
        dp[idx]=a[i];
    }
    printf("%d\n",n-cnt);
    return 0;
}
