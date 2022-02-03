/*
    TASK:Stair_Wood
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100];
int main(){
    int n,idx,cnt=0,i,num;
    int q;
    scanf("%d",&q);
    while(q--){
    scanf("%d",&n);
    cnt=0;
    for(i=0;i<n;i++){
        scanf("%d",&num);
        idx=lower_bound(dp,dp+cnt,num)-dp;
        //if(idx>=1 && dp[idx-1]==num) continue;
        if(idx==cnt) cnt++;
        dp[idx]=num;
    }
    printf("%d\n",cnt);
    }
    return 0;
}
