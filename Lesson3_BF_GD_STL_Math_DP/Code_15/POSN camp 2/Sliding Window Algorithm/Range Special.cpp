/*
    TASK:Range Special
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
deque<long long> Ma,Mi;
long long a[1000100],n;
long long fi(long long q){
    long long ans=0,Maidx=0,Miidx=0,i;
    for(i=1;i<=n;i++){
        while(!Ma.empty() && a[i]>a[Ma.back()])Ma.pop_back();
        while(!Mi.empty() && a[i]<a[Mi.back()])Mi.pop_back();
        Ma.push_back(i),Mi.push_back(i);
        while(a[Ma.front()]-a[Mi.front()]>q){
            if(Mi.front()<Ma.front()) Miidx=Mi.front(),Mi.pop_front();
            else                      Maidx=Ma.front(),Ma.pop_front();
        }
        ans+=i-max(Miidx,Maidx);
    }
    while(!Ma.empty())Ma.pop_back();
    while(!Mi.empty())Mi.pop_back();
    return ans;
}
int main(){
    long long p,q,ans,i;
    scanf("%lld %lld %lld",&n,&p,&q);
    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    ans = fi(q);
    if(p) ans-=fi(p-1);
    printf("%lld\n",ans);
    return 0;
}
