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
    long long n,m,i,l,r,mid,ans;
    scanf("%lld %lld",&m,&n);
    for(i=1; i<=m; i++)
    {
        scanf("%lld",&a[i]);
    }
    l=0,r=1e18;
    while(l<r)
    {
        mid=(l+r)/2;
        ans=0;
        for(i=1; i<=m; i++)
        {
            ans+=mid/a[i];
        }
        if(ans>=n){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    printf("%lld\n",l);
}
