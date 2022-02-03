/*
    TASK:Swift Spider
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int main(){
    long long n,t,i,l,r,mid,cou,now,st,ma=0,en;
    scanf("%lld %lld",&n,&t);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        ma=max(ma,a[i]);
    }
    if(t==1){printf("-1\n");return 0;}
    l=ma,r=1e18;
    while(l<r){
        mid=(l+r)/2;
        cou=0;
        now=0;
        for(i=1;i<=n;i++){
            if(a[i]>now)cou++,now=mid;
            now-=a[i];
        }
        //printf("%lld %lld\n",mid,cou);
        if(cou>t)l=mid+1;
        else r=mid;
    }
    st=r;
    //printf("%lld\n",st);
    l=st,r=1e18;
    while(l<r){
        mid=(l+r)/2;
        cou=0;
        now=0;
        for(i=1;i<=n;i++){
            if(a[i]>now)cou++,now=mid;
            now-=a[i];
        }
        //printf("%lld %lld\n",mid,cou);
        if(cou==t)l=mid+1;
        else r=mid;
    }
    en=r;
    printf("%lld\n",en-st);
    return 0;
}
