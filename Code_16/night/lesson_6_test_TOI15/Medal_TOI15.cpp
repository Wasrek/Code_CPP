/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long t[500010],h[500010],a[500010];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&t[i]);
    }
    sort(t+1,t+1+n);
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    sort(h+1,h+1+n,greater<long long>());
    for(int i=1;i<=n;i++){
        a[i]=t[i]+h[i];
    }
    sort(a+1,a+1+n);
    long long ans=0;
    for(int i=2;i<=n;i++){
        ans+=(a[i]-a[i-1]);
    }
    printf("%lld\n",ans);
    return 0;
}