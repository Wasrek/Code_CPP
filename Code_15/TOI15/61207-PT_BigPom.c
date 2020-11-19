/*
    TASK:PT_Big Pom
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long b[100100],n,c,R,s;
long long dc(long long l,long long r){
    long long ll,lr,h,now;
    ll=lower_bound(b+1,b+c+1,l)-b;
    lr=upper_bound(b+1,b+c+1,r)-b;
    now=lr-ll;
    if(now==0)
        return R;
    if(l==r)
    {
        if(now==0)
            return R;
        else
            return s;
    }
    long long mid=(l+r)/2,k,mr,ml;
    mr=dc(l,mid);
    ml=dc(mid+1,r);
    if(now==0)
        k=R;
    else
        k=(r-l+1)*s*now;
    return min(k,mr+ml);
}
int main(){
    long long q,i,ans,d;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld %lld %lld",&n,&c,&R,&s);
        for(i=1;i<=c;i++)scanf("%lld",&b[i]);
        sort(b+1,b+1+c);
        d=1<<n;
        ans=dc(1,d);
        printf("%lld\n",ans);
    }
}
