/*
    TASK:LeftShift
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100];
int main()
{
    int n,m,q,s,e,b,i,v;
    scanf("%d %d %d",&n,&m,&q);
    while(m--){
        scanf("%d %d %d",&s,&e,&v);
        dp[s]+=v,dp[e+1]-=v;
    }
    for(i=1;i<=n;i++)
        dp[i]+=dp[i-1];
    while(q--){
        scanf("%d",&b);
        printf("%d\n",dp[b]);
    }
    return 0;
}
