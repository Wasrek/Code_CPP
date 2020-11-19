/*
    TASK: Mod of power
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long ModofPower(long long a,long long b,long long c)
{
    if(b==1)
        return a%c;
    long long t=ModofPower(a,b/2,c);
    if(b%2==0)
        return (t*t)%c;
    else
        return (t*t*a)%c;
}
int main()
{
    long long q,a,b,c;
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        printf("%lld\n",ModofPower(a,b,c));
    }
    return 0;
}
