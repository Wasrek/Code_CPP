/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long s,t,mi,ma;
    bool operator<(const A & o) const{
        if(ma!=o.ma) return ma<o.ma;
        return t<o.t;
    }
};
A a[1000010];
long long dp[1000010];
int main()
{
    long long n,st;
    scanf("%lld %lld",&n,&st);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld",&a[i].s,&a[i].t);
        a[i].mi=a[i].t-a[i].s;
        a[i].ma=a[i].s+a[i].t;
    }
    long long cnt,idx;
    cnt=0;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[i].mi<0-st || a[i].ma<st) continue;
        idx=upper_bound(dp,dp+cnt,a[i].mi)-dp;
        if(idx == cnt)
            cnt++;
        dp[idx]=a[i].mi;
        // printf("%d %d\n",a[i].mi,a[i].ma);
    }
    // printf("%d %d\n",cnt1,cnt2);
    printf("%lld\n",cnt);
    return 0;
}