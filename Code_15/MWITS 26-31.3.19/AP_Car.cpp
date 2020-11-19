/*
    TASK:AP_Car
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long s,e;
    bool operator <(const A&o) const{
        if(s!=o.s)return s<o.s;
        return e>o.e;
    }
};
A a[100100];
int main(){
    long long q,n,t,i,v,ans,st,last;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&n,&t);
        for(i=0;i<n;i++){
            scanf("%lld %lld",&a[i].s,&v),a[i].e=a[i].s+v*t;
        }
        sort(a,a+n);
        ans=1,st=a[0].s,last=a[0].e;
        for(i=1;i<n;i++){
            if(a[i].e<last || a[i].e==last && a[i].s>st)continue;
            ans++;
            st=a[i].s,last=a[i].e;
        }
        printf("%d\n",ans);
    }
    return 0;
}
