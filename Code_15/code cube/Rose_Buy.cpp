/*
    TASK:Rose Buy
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000005],ans=-1e18;
int main(){
    int n,k,i;
    scanf("%d %d",&n,&k);
    a[n+1]=-1e18;
    for(i=1;i<=n;i++)scanf("%lld",&a[i]),a[i]+=a[i-1];
    for(i=n;i>=0;i--){
        if(i+k<=n)ans=max(ans,a[i+k]-a[i]);
        a[i]=max(a[i],a[i+1]);
    }
    printf("%lld",ans);
    return 0;
}
