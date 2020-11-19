/*
    TASK:FC_Rose Buy
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000010],qs[1000010],mi[1000010];
int main(){
    long long n,k,i,ans=-1e18;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        qs[i]=qs[i-1]+a[i];
        mi[i]=min(qs[i],mi[i-1]);
        if(i-k>=0)
        ans=max(ans,qs[i]-mi[i-k]);
    }
    printf("%lld",ans);
}
