/*
    TASK:Swift Wood Cut
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long h[1000100];
int main()
{
    long long a,b,i,l,r,mid,sum;
    scanf("%lld %lld",&a,&b);
    for(i=0; i<a; i++)
    {
        scanf("%lld",&h[i]);
    }
    l=0,r=2000000000;
    while(l<r)
    {
        mid=(l+r+1)/2;
        sum=0;
        for(i=0; i<a; i++)
        {
            if(h[i]>mid)sum+=h[i]-mid;
        }
        if(sum>=b)l=mid;
        else r=mid-1;
    }
    printf("%lld\n",r);
    return 0;
}
