/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000003
int main()
{
    long long a,b,ans=1ll,div=1,divp=1;
    scanf("%lld %lld",&a,&b);
    for(long long i=b+1;i<=a;i++)ans=(ans*i)%MOD;
    //Fermat’s little theorem a^(-1) ≡ a^(m-2) (mod m)
    for(long long i=1;i<=(a-b);i++) div=(div*i)%MOD;
    for(long long i=1;i<=MOD-2;i++) divp=(divp*div)%MOD;
    ans=(ans*divp)%MOD;
    printf("%lld\n",ans);
    return 0;
}