/*
    TASK:PT_Subway
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
deque<pair<int,int>> dq;
int dp[10100],a[10100];
int main(){
    int q,n,i,j,ans,k;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        dq.push_back({0,0});
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            while(!dq.empty() && dq.front().second==0 && i-k>1)dq.pop_front();//it not cover the first one
            while(!dq.empty() && i-dq.front().second-(2*k)>1)dq.pop_front();//not cover even we choose this one
            dp[i]=a[i]+dq.front().first;
            while(!dq.empty() && dq.back().first>=dp[i])dq.pop_back();
            dq.push_back({dp[i],i});
        }
        ans=1<<30;
        for(i=n;i>=n-k;i--){
            if(i>0)
            ans=min(ans,dp[i]);
        }
        printf("%d\n",ans);
        while(!dq.empty())dq.pop_back();
    }
}
