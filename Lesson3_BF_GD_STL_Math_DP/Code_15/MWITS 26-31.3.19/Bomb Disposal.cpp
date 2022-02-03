/*
    TASK:Bomb Disposal
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long s,m,l,r,mid,ans,ch=0;
    scanf("%lld %lld",&s,&m);
    l=0,r=s/2;
    while(l<r)
    {
        mid=(l+r)/2;
        if(mid>=1e19/(s-mid) || mid*(s-mid)>=m)r=mid;
        else l=mid+1;
    }
    if(l*(s-l)==m){
        printf("%lld %lld",l,s-l);
    }else printf("Goodbye T-T");
    return 0;
}
