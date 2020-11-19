/*
    TASK:Plate Sort3
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int main(){
    int i,j,q,n,k;
    dp[1][1]=1;
    for(i=2;i<=1000;i++){
        for(j=1;j<=i;j++){
            dp[i][j]=(dp[i-1][j]*j+dp[i-1][j-1])%9871;
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        printf("%d\n",dp[n][k]);
    }
    return 0;
}
