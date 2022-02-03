/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long h,c;
    bool operator<(const A & o) const{
        if(c!=o.c) return c<o.c;
        return h<o.h;
    }
};
A a[500010];
long long qsh[500010],qsc[500010];
int main()
{
    long long n,now,minh,ans,idx;
    minh=ans=1e18;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i].h);
        minh=min(minh,a[i].h);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i].c);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        qsh[i]=qsh[i-1]+a[i].h;
        qsc[i]=qsc[i-1]+a[i].c;
    }
    for(int i=1;i<=n;i++){
        if(a[i].c>minh) break;
        now=(qsc[n]-qsc[i])-(a[i].c*(n-i))+(qsc[i-1])+(qsh[i-1]-(a[i].c*(i-1)));
        // printf("%lld %lld\n",now,a[i].c);
        if(now<ans){
            ans=now;
            idx=a[i].c;
        }
    }
    printf("%lld %lld",idx,ans);
    return 0;
}