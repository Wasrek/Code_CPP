/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,idx;
};
deque< A > dq[3010];
int dp[3010][3010],a[3010];
int main()
{
    int n,k,ans=2e9;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        for(int j=1;j<i;j++){
            dp[i][j]=2e9;
            if(i<=k && j<=k) dp[i][j]=a[i]+a[j];
            while(!dq[j].empty() && dq[j].front().idx+k-1<i-1) dq[j].pop_front();
            if(!dq[j].empty())dp[i][j]=min(dp[i][j],dq[j].front().v+a[i]);
            while(!dq[i].empty() && dq[i].back().v>dp[i][j]) dq[i].pop_back();
            dq[i].push_back({dp[i][j],j});
            if(i>n-k && j>n-k) ans=min(ans,dp[i][j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}