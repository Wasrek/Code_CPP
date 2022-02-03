#include<bits/stdc++.h>
using namespace std;
long long qs[1000100],dp[1000100];
deque< pair<long long,long long> > ma;
int main()
{
    long long n,k,i;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++)   scanf("%lld",&qs[i]),qs[i]+=qs[i-1];
    ma.push_back({0,0});
    for(i=1;i<=n;i++){
        while(!ma.empty() && qs[i]-ma.front().second>k)  ma.pop_front();
        dp[i] = dp[i-1];
        if(!ma.empty()) dp[i] = max(dp[i],qs[i]+ma.front().first);
        while(!ma.empty() && -qs[i]+dp[i-1]>=ma.back().first)   ma.pop_back();
        ma.push_back({-qs[i]+dp[i-1],qs[i]});
    }
    printf("%lld",dp[n]);
    return 0;
}
