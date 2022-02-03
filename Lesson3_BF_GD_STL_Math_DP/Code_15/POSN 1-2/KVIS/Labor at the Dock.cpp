/*
    TASK:Labor at the Dock
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000100];
int main()
{
    long long n,m,mid,l,r,i,sum;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    l=0,r=1e18;
    while(l<r){
        mid = (l+r)/2;
        for(i=0,sum=0;i<n;i++)
            sum+= mid/a[i];
        if(sum>=m) r=mid;
        else l=mid+1;
    }
    printf("%lld\n",l);
    return 0;
}
