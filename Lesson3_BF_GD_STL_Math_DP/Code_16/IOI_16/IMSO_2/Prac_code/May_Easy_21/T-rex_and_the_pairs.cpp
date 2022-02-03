/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100],mi[100100],pl[100100];
int main()
{
    long long n,ans=0,lb,ub;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        pl[i]=(long long)pow((double)(i),2.0)+a[i];
        mi[i]=a[i]-(long long)pow((double)(i),2.0);
    }
    sort(mi+1,mi+1+n);
    for(int i=1;i<=n;i++){
        lb=lower_bound(mi+1,mi+1+n,pl[i])-mi;
        ub=upper_bound(mi+1,mi+1+n,pl[i])-mi;
        ans+=(ub-lb);
    }
    printf("%lld\n",ans);
    return 0;
}