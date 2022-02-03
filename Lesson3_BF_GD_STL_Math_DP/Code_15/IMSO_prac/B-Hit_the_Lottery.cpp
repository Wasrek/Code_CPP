/*
    TASK:B-Hit_the_Lottery
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,sum=0;
    scanf("%lld",&a);
    sum+=(a/100);
    a%=100;
    sum+=(a/20);
    a%=20;
    sum+=(a/10);
    a%=10;
    sum+=(a/5);
    a%=5;
    sum+=a;
    printf("%lld\n",sum);
    return 0;
}
