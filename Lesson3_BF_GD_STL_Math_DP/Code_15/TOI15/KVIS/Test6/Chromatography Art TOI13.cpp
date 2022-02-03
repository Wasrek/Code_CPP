/*
    TASK:Chromatography Art TOI13
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long s,h,v;
    bool operator<(const A&o)const{
    return s<o.s;
    }
};
A event[200010];
long long fw[1000010];
int main(){
    long long n,t,i,s,h,w,o,k,l,r,mid,low,hig,sum,ans=0;
    scanf("%lld %lld",&n,&t);
    for(i=0;i<n;i++){
        scanf("%lld %lld %lld %lld",&s,&h,&w,&o);
        event[i*2+1]={s,h,o};
        event[i*2+2]={s+w,h,-o};
    }
    sort(event+1,event+2*n+1);
    event[2*n+1].s=event[2*n].s+1;
    for(i=1;i<=2*n;i++){
        for(k=1;k<=1000000;k+=(k&-k)){
            fw[k]+=event[i].v;
        }
        for(k=1+event[i].h;k<=1000000;k+=(k&-k)){
            fw[k]-=event[i].v;
        }
        if(event[i].s==event[i+1].s)continue;
        l=1;r=1000000;
        while(l<r){
            mid=(l+r)/2;
            sum=0;
            for(k=mid;k>0;k-=(k&-k)){
                sum+=fw[k];
            }
            if(sum>t)
                l=mid+1;
            else r=mid;
        }
        low=l;
        l=1;r=1000000;
        while(l<r){
            mid=(l+r)/2;
            sum=0;
            for(k=mid;k>0;k-=(k&-k)){
                sum+=fw[k];
            }
            if(sum>=t)
                l=mid+1;
            else r=mid;
        }
        hig=l;
        //printf("%lld %lld %lld %lld\n",hig,low,event[i].s,event[i+1].s);
        ans+=(hig-low)*(event[i+1].s-event[i].s);
    }
    printf("%lld",ans);
}
/*
3 3
1 1 4 1
2 2 2 2
3 3 1 3
*/
