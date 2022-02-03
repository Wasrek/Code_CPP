/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a0,a1,a2,b0,b1,b2,now;
    long long ans=0;
    scanf("%d %d %d",&a0,&a1,&a2);
    scanf("%d %d %d",&b0,&b1,&b2);
    now=min(a2,b1);
    ans+=(now*2);
    a2-=now;
    b1-=now;
    now=min(a2,b2);
    a2-=now;
    b2-=now;
    now=min(a1,b1);
    a1-=now;
    b1-=now;
    now=min(a0,b2);
    a0-=now;
    b2-=now;
    now=min(a1,b0);
    a1-=now;
    b0-=now;
    now=min(a1,b2);
    ans-=(now*2);
    printf("%lld\n",ans);
    return 0;
}