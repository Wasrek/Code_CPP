/*
    TASK:Group_Manage
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100];
int main(){
    int q;
    scanf("%d",&q);
    int n,cnt=0,idx,i,num;
    while(q--){
    cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        idx=upper_bound(dp,dp+cnt,num)-dp;
        if(idx==cnt)cnt++;
        dp[idx]=num;
    }
    printf("%d",cnt);
    }
}
