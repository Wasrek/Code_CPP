/*
    TASK:Pair
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,b;
    bool operator <(const A&o) const{
        return b<o.b;
    }
};
A p[100100];
long long a[100100],b[100100],ans,qs[100100];
void mergesort(long long l,long long r){
    if(l==r)return ;
    long long mid,i,j,k;
    mid=(l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    qs[l-1]=0;
    for(i=l;i<=r;i++)
        qs[i]=qs[i-1]+a[i];
    i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
            ans+=(qs[mid]-qs[i-1]+(mid-i+1)*a[j]),b[k++]=a[j++];
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=r)
        b[k++]=a[j++];
    for(i=l;i<=r;i++)
        a[i]=b[i];
}
int main(){
    long long n,i;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        scanf("%lld %lld",&p[i].a,&p[i].b);
    sort(p+1,p+n+1);
    for(i=1;i<=n;i++)
        a[i]=p[i].a;
    mergesort(1,n);
    printf("%lld\n",ans);
    return 0;
}
/*
6
2 1 7 6 9 3 18 4 3 2 5 5
*/
