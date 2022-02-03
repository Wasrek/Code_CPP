/*
    TASK: Router Internet
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100050];
int main()
{
    long long i,m,n,l,r,mid,sum,Max=0,coun;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    l=Max,r=1ll<<31;
    while(l<r){
        mid=(l+r)/2;
        sum=0,coun=1;
        for(i=0;i<n;i++){
            if(sum+a[i]>mid)
                coun++,sum=a[i];
            else
                sum+=a[i];
        }
        if(coun<=m) r=mid;
        else        l=mid+1;
    }
    printf("%lld",l);
    return 0;
}
