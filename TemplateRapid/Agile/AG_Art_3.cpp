/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main()
{
    long long ans,t,q,a,b,c,d;
    scanf("%lld %lld",&t,&q);
    while(q--){
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        ans=((a%MOD)*((a-1+MOD)%MOD))%MOD;
        ans/=2;
        ans%=MOD;
        ans*=3;
        ans%=MOD;
        ans+=(3*a)%MOD;
        ans+=3;
        printf("%lld\n",ans%MOD);
    }
    return 0;
}