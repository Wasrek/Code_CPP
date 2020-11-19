/*
    TASK:Peatt_Punch
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010],dp[100010];
struct A{
    long long h,i; 
};
stack < A > st;
int main()
{
    int l,q;
    scanf("%d %d",&l,&q);
    for(int i=1;i<=l;i++){
        scanf("%d",&a[i]);
        while(!st.empty() && st.top().h>a[i]) st.pop();
        if(st.empty()){
            dp[i]=0;
            st.push({a[i],i});
            continue;
        }
        // printf("%d %d\n",i,st.top().i);
        dp[i]=max(dp[st.top().i],a[i]-st.top().h);
        st.push({a[i],i});
    }
    // for(int i=1;i<=l;i++) cout << dp[i] << " ";
    // cout << endl;
    long long now;
    sort(dp+1,dp+1+l);
    while(q--){
        scanf("%lld",&now);
        now=upper_bound(dp+1,dp+1+l,now)-dp;
        printf("%lld\n",l-now+1);
    }
    return 0;
}