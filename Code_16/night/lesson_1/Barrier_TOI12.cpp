/*
    TASK:Barrier TOI12
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,v;
};
deque< A > dq;
long long a[6000100];
int main()
{
    long long n,m,ma=0,l=0;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    dq.push_back({0,0});
    for(int i=1;i<=n;i++){
        while(!dq.empty() && i-dq.front().i>m) dq.pop_front();
        while(!dq.empty() && a[i]<dq.back().v)dq.pop_back();
        dq.push_back({i,a[i]});
        if(a[i]-dq.front().v>ma){
            ma=a[i]-dq.front().v;
            l=i-dq.front().i;
        }
        // printf("%d ",dq.front().i);
        if(a[i]-dq.front().v==ma) l=min(l,i-dq.front().i);
    }
    printf("%lld %lld",ma,l);
    return 0;
}