/*
    TASK:AP_3Rotate
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100],b[100100],ans,n;
void mergesort(long long l,long long r){
    if(l==r)return ;
    long long i,j,k,mid;
    mid=(l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    i=l,k=l,j=mid+1;
    while(i<=mid && j<=r){
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else if(a[i]>a[j])
            b[k++]=a[j++],ans+=(mid-i+1);
    }
    while(i<=mid){
        b[k++]=a[i++];
    }
    while(j<=r){
        b[k++]=a[j++];
    }
    for(i=l;i<=r;i++){
        a[i]=b[i];
    }
}
int main(){
    long long q,i;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        ans=0;
        mergesort(0,n-1);
        printf((ans%2==0)?"yes\n":"no\n");
    }
    return 0;
}
