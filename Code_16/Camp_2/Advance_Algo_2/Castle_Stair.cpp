/*
    TASK:Castle Stair
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int h[100010],dp[100010];
int main()
{
    int q,n,k,idx;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&h[i]);
        }
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1];
            idx=lower_bound(h+1,h+1+i,h[i]-k)-h;
            dp[i]+=(dp[i-1]-dp[idx-1]);
            dp[i]%=95959;
            dp[i]+=95959;
            dp[i]%=95959;
        }
        printf("%d\n",(dp[n]-dp[n-1]+95959)%95959);
    }
    return 0;
}