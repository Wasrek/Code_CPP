/*
    TASK:Roam
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100];
int main()
{
    int n,m,a,b,i,q;
    scanf("%d %d",&n,&m);
    while(m--)
    {
        scanf("%d %d",&a,&b);
        dp[a]++,dp[b+1]--;
    }
    for(i=1;i<=n;i++)
        dp[i]+=dp[i-1];
    scanf("%d",&q);
    while(q--){
        scanf("%d",&a);
        printf("%d\n",dp[a]);
    }
    return 0;

}
