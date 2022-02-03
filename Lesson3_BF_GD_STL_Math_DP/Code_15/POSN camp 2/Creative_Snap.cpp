/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include <bits/stdc++.h>
using namespace std;
long long a[100010];
long long k,A,B;
long long divide(long long l,long long r){
    if(l==r){
        long long rr = upper_bound(a+1,a+1+k,r)-1-a;
        long long ll = lower_bound(a+1,a+1+k,l)-a;
        long long cost = 0;
        if(rr-ll+1>0){
            cost = B * (rr-ll+1) * (r-l+1);
        }
        else cost = A;
        return cost;
    }
    long long mid = (l+r)/2;
    long long rr = upper_bound(a+1,a+1+k,r)-1-a;
    long long ll = lower_bound(a+1,a+1+k,l)-a;
    if(rr-ll+1<=0){
            return A;
    }
    return min(divide(l,mid)+divide(mid+1,r),B * (rr-ll+1) * (r-l+1));
}
int main()
{
    long long n;
    scanf("%lld %lld %lld %lld",&n,&k,&A,&B);
    n = 1<<n;
    for(long long i=1;i<=k;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+k+1);
    printf("%lld\n",divide(1,n));
    return 0;
}