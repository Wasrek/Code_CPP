/*
    TASK:Castle King
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[500100];
int main()
{
    long long i,n,ans=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++){
        ans+=2*a[i];
        ans+=a[i]-a[i-1];
    }
    ans+=n+a[n];
    printf("%lld",ans);
    return 0;
}
