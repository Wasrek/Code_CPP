/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010];
int main()
{
    int q,n,i,j;
    dp[1]=dp[2]=1;
    for(i=3;i<=1000;i++){
        for(j=1;j<=i-1;j++){
            dp[i]+=dp[j]*dp[i-j];
            dp[i]%=9973;
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}
