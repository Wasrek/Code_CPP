/*
    TASK:KarnKuay
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100];
int main(){
    int n,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        dp[i]=dp[i-1];
        if(i>=3) dp[i]=max(dp[i],x+dp[i-3]);
    }
    printf("%d\n",dp[n]);
}
//12 1 2 5 4 3 0 6 1 2 7 2 1
