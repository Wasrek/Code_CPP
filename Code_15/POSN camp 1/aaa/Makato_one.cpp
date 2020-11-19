/*
    TASK:Makato_one
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100];
int main()
{
    int n,q,i,j;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&dp[i]);
        dp[i]^=dp[i-1];
    }
    while(q--){
        scanf("%d %d",&i,&j);
        printf("%d\n",dp[j]^dp[i-1]);
    }
    return 0;

}
