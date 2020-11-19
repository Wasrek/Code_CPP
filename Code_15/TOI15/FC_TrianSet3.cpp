/*
    TASK:FC_TrianSet3
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[400010];
int main(){
    long long n,i,now,ans=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(i=1;i<=n-3+1;i++){
        now=lower_bound(a+1,a+1+n,a[i]+a[i+1])-a;
        now--;
        ans=max(ans,now-i+1);
    }
    printf("%lld\n",ans);
    return 0;
}
