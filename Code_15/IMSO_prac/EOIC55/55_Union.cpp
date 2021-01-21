/*
    TASK:55_Union
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long y,x;
    bool operator<(const A&o) const{
        if(y!=o.y)return y>o.y;
        else return x<o.x;
    }
};
A s[1000020];
int main()
{
    long long n,a,b,i,ma=0;
    long long ans=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&a,&b);
        a/=2;
        b/=2;
        s[i].y=a;
        s[i].x=b;
    }
    sort(s+1,s+1+n);
    s[n+1].y=s[n+1].x=0;
    for(i=1;i<=n;i++){
        if(s[i].y==s[i+1].y){continue;}
        if(s[i].x<ma)s[i].x=ma;
        ans+=(s[i].y-s[i+1].y)*s[i].x;
        ma=max(ma,s[i].x);
    }
    printf("%lld\n",ans*4);
    return 0;
}
