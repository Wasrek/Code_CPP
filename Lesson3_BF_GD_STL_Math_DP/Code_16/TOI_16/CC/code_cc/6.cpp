/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000100];
int main()
{
    long long n,all=0,mss=0,now=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(i%2) a[i]*=-1;
        all+=a[i];
        now+=a[i];
        if(now<0)now=0;
        else mss=max(mss,now);
    }
    printf("%lld\n",all-(mss*2));

    return 0;
}