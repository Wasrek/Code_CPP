#include<bits/stdc++.h>
using namespace std;
#define mod 500000003
const int N = 2000005;
long long mow(long long a,long long b)
{
    a%=mod;
    if(b==0)    return 1;
    if(b==1)    return a%mod;
    long long c=mow(a,b/2);
    c*=c,c%=mod;
    if(b%2) c*=a,c%=mod;
    return c;
}
long long fac[N];
int main()
{
    long long q,a,b,c,d;
    scanf("%lld",&q);
    fac[0]=1ll;
    for(long long i=1;i<=2000000;i++)   fac[i]=(fac[i-1]*i)%mod;
    while(q--)
    {
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        if(c<a||d<b)
        {
            printf("0\n");
            continue;
        }
        long long e=(c-a)+(d-b),f=c-a,g=d-b,ans;
        ans=(fac[e]*mow(fac[f],mod-2ll))%mod;
        ans*=mow(fac[g],mod-2ll);
        ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
