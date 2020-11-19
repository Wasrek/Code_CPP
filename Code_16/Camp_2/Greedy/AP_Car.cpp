/*
    TASK:AP_Car
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long x,v;
    bool operator<(const A & o) const{
        if(x!=o.x) return x<o.x;
        else return v>o.v;
    }
};
A a[100010];
int main()
{
    long long q,n,t,ma,cnt,st,now;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&n,&t);
        for(int i=1;i<=n;i++){
            scanf("%lld %lld",&a[i].x,&a[i].v);
            a[i].v=a[i].x+(a[i].v*t);
        }
        sort(a+1,a+1+n);
        ma=0;
        cnt=0;
        now=0;
        // printf("%d %d\n",ma,cnt);
        for(int i=1;i<=n;i++){
            if(ma>a[i].v || (ma==a[i].v && now!=a[i].x)){
                cnt++;
                // printf("%d %d\n",ma,a[i].v);
                continue;
            }else{
                ma=a[i].v;
                now=a[i].x;
            }
        }
        printf("%lld\n",n-cnt);
    }
    return 0;
}