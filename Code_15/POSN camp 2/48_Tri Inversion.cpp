/*
    TASK:
    LANG: CPP
    AUTHOR: 
    SCHOOL: 
*/
#include<bits/stdc++.h>
using namespace std;
#define M 100100
long long a[M],b[M],ll[M],rr[M],idx[M],tmp[M];
void ms(long long l,long long r){
    if(l==r) return;
    long long mid=(l+r)/2,i,j,k;
    ms(l,mid); ms(mid+1,r);
    i=k=l,j=mid+1;
    while(i<=mid && j<=r){
        if(a[i]<=a[j])
            tmp[k]=idx[i],rr[idx[i]]+=j-mid-1,b[k++]=a[i++];
        else
            tmp[k]=idx[j],ll[idx[j]]+=mid-i+1,b[k++]=a[j++];
    }
    while(i<=mid)
        tmp[k]=idx[i],rr[idx[i]]+=r-mid,b[k++]=a[i++];
    while(j<=r)
        tmp[k]=idx[j],b[k++]=a[j++];
    for(i=l;i<=r;i++)
        a[i]=b[i],idx[i]=tmp[i];
}
int main()
{
    long long q,ans,i,n;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
            scanf("%lld",&a[i]),idx[i]=i;
        ms(1,n);
        for(i=1,ans=0;i<=n;i++)
            ans+=(ll[i]*rr[i]);
        printf("%lld\n",ans);
        memset(ll,0,sizeof ll) ,memset(rr,0,sizeof rr);
    }
    return 0;
}
