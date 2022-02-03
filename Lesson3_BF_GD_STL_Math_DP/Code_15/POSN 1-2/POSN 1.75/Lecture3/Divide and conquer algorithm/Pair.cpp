/*
    TASK:Pair
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> a[100100];
long long qs[100100],b[100100];
long long ans;
void mergesort(long long l,long long r){
    if(l==r)return ;
    //printf("%lld")
    long long mid=(l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    qs[l-1]=0;
    for(long long i=l;i<=mid;i++){
        qs[i]=qs[i-1]+a[i].second;
    }
    long long i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(a[i].second<=a[j].second)
            b[k++]=a[i++].second;
        else{
            ans+=qs[mid]-qs[i-1]+a[j].second*(mid-i+1);
            b[k++]=a[j++].second;
        }
    }
    while(i<=mid)
        b[k++]=a[i++].second;
    while(j<=r)
        b[k++]=a[j++].second;
    for(i=l;i<=r;i++)
        a[i].second=b[i];
    return ;
}
int main(){
    long long n;
    scanf("%lld",&n);
    long long i;
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&a[i].second,&a[i].first);
    }
    sort(a+1,a+n+1);
    mergesort(1,n);
    printf("%lld\n",ans);
}
/*
6
2 1 7 6 9 3 18 4 3 2 5 5
*/
