/*
    TASK:Codnan
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[100100];
int main()
{
    long long n,k,j,l,r,x,mid,i,sum;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%lld",&dp[i]);
        dp[i]+=dp[i-1];
    }
    while(k--){
    scanf("%lld",&x);
    l=0,r=n;
    while(l<r){
        mid=(l+r+1)/2;
        if(dp[mid]<=x) l=mid;
        else r=mid-1;
    }
    printf("%lld\n",l);
    }

    return 0;
}
