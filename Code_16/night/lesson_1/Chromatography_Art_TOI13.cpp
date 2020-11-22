/*
    TASK:Chromatography art TOI13
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,h,o;
    bool operator <(const A & o) const{
        return i<o.i;
    }
};  
A event[200100];
long long fw[1000100];
int main()
{
    long long n,t,s,h,w,o,mah=0,lb,ub,l,r,mid,sum,cnt=0;
    scanf("%lld %lld",&n,&t);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld %lld %lld",&s,&h,&w,&o);
        event[(i*2)-1].i=s;
        event[(i*2)-1].h=h;
        event[(i*2)-1].o=o;
        event[i*2].i=s+w;
        event[i*2].h=h;
        event[i*2].o=-o;
        mah=max(mah,h);
    }
    sort(event+1,event+1+(2*n));
    event[(2*n)+1].i=event[(2*n)].i+1;
    for(int i=1;i<=n*2;i++){
        for(int j=1;j<=1000000;j+=(j&-j)){
            fw[j]+=event[i].o;
        }
        for(int j=event[i].h+1;j<=1000000;j+=(j&-j)){
            fw[j]-=event[i].o;
        }
        if(event[i].i==event[i+1].i) continue;
        l=1,r=1000000;
        while(l<r){
            mid=(l+r)/2;
            sum=0;
            for(int j=mid;j>0;j-=(j&-j)) sum+=fw[j];
            if(sum>t){
                l=mid+1;
            } else r=mid;
        }
        lb=l;
        l=1,r=1000000;
        while(l<r){
            mid=(l+r)/2;
            sum=0;
            for(int j=mid;j>0;j-=(j&-j)) sum+=fw[j];
            if(sum>=t){
                l=mid+1;
            }else r=mid;
        }
        ub=l;
        cnt+=(ub-lb)*(event[i+1].i-event[i].i);
    }
    printf("%lld\n",cnt);
    return 0;
}