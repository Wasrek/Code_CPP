/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,v;
    bool operator<(const A & o) const{
        return i<o.i;
    }
};
A event[200100];
int main()
{
    long long n,a,b,sum=0;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&a,&b);
        event[i*2+1]={a,1};
        event[i*2+2]={b+1,-1};
    }
    sort(event+1,event+1+2*n);
    for(int i=1;i<n*2;i++){
        event[i].v+=event[i-1].v;
        if(event[i].i==event[i+1].i) continue;
        if(!event[i].v) continue;
        sum+=(event[i+1].i-event[i].i)*(event[i].v-1);
    }
    printf("%lld\n",sum);
    return 0;
}