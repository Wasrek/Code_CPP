/*
    TASK:Chromatography Art TOI13
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    long long s,h,v;
    bool operator<(const A&o)const
    {
        return s<o.s;
    }
};
A event[200100];
long long fw[1000100];
int main()
{
    long long n,s,h,w,o,cou=0,j,up,lo,t,k,i,v,l,r,ans,mid;
    scanf("%lld %lld",&n,&t);
    for(i=0; i<n; i++)
    {
        scanf("%lld %lld %lld %lld",&s,&h,&w,&v);
        event[i*2+1]= {s,h,v};
        event[i*2+2]= {s+w,h,-v};
    }
    sort(event+1,event+2*n+1);
    event[2*n+1].s=event[2*n].s+1;
    for(i=1; i<=2*n; i++)
    {
        for(k=1; k<=1000000; k+=(k&-k))
        {
            fw[k]+=event[i].v;
        }
        for(k=1+event[i].h; k<=1000000; k+=(k&-k))
        {
            fw[k]-=event[i].v;
        }
        if(event[i].s==event[i+1].s)
            continue;
        l=1, r=1000000;
        while(l<r)
        {
            mid=(l+r)/2;
            ans=0;
            for(int k=mid;k>=1;k-=k&-k)ans+=fw[k];
            if(ans>t)
                l=mid+1;
            else
                r=mid;
        }
        lo=l;
        l=1, r=1000000;
        while(l<r)
        {
            mid=(l+r)/2;
            ans=0;
            for(int k=mid;k>=1;k-=k&-k)ans+=fw[k];
            if(ans>=t)
                l=mid+1;
            else
                r=mid;
        }
        up=l;
        cou+=(up-lo)*(event[i+1].s-event[i].s);
    }
    printf("%lld\n",cou);
}
