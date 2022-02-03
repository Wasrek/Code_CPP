/*
    TASK:Loose Summation
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[2100];
int main()
{
    int n,k,i,j,l,q;
    scanf("%d",&q);
    dp[0]=1;
    for(i=1;i<=2000;i++){
        for(j=2000;j>=i;j--){
            if(dp[j-i]){
                dp[j]+=dp[j-i]%1000003;
            }
        }
    }
    while(q--){
    scanf("%d",&n);
    printf("%d\n",(dp[n])%1000003);
    }

    return 0;
}
