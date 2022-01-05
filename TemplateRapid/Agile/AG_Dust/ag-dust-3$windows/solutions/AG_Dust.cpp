/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 200100
struct A{
    long long x,y;
    bool operator <(const A& o) const{
        if(x!=o.x) return x<o.x;
        return y<o.y;
    }
};
A a[N];
long long le[N],ri[N];
int main()
{
    long long q,n,xii,xaa,mii,maa,diff,as;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld %lld\n",&a[i].x,&a[i].y);
            if(a[i].x>1000000000 || a[i].x<-1000000000) printf("%lld\n",a[i].x);
            if(a[i].y>1000000000 || a[i].y<-1000000000) printf("%lld\n",a[i].y);
        }
        sort(a+1,a+1+n);
        le[1]=a[1].y;ri[n]=a[n].y;
        for(int i=2;i<=n;i++){
            le[i]=min(le[i-1],a[i].y);
        }
        for(int i=n-1;i>=1;i--){
            ri[i]=max(ri[i+1],a[i].y);
        }
        long long ans=1;
        for(int i=1;i<n;i++){
            if(le[i]>ri[i+1]){
                ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}