#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> a[100100];
int main()
{
    long long n,m,i,ans=0;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld",&a[i].first,&a[i].second);
    }
    sort(a,a+n);
    for(i=1;i<n;i++)
        if(a[i-1].second > a[i].second)
        ans+=a[i-1].second - a[i].second;
    printf("%lld\n",ans+a[n-1].second);
    return 0;
}
