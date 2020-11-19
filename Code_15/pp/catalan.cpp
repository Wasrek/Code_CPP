/*
    TASK:catalanprac
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010];
int main(){
    int i,j,n,q;
    dp[1]=dp[2]=1;
    for(i=3;i<=1000;i++){
        for(j=1;j<i;j++){
            dp[i]+=dp[j]*dp[i-j];
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
}
