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
    long long n,m,mid,have;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    long long l=0, r=1e18;
    while(l<r){
        mid=(l+r)/2;
        have=0;
        for(int i=1;i<=n;i++){
            have+=(mid/a[i]);
        }
        if(have>=m) r=mid;
        else l=mid+1;
    }
    printf("%lld\n",l);
    return 0;
}