/*
    TASK:FC_Bridge
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100],b[100100],ans;
void ms(long long l,long long r){
    if(l==r)return ;
    long long mid=(l+r)/2;
    ms(l,mid);
    ms(mid+1,r);
    long long i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            b[k++]=a[i++];
        }
            else{
                b[k++]=a[j++];
                ans+=mid-i+1;
            }
    }
    while(i<=mid)b[k++]=a[i++];
    while(j<=r)b[k++]=a[j++];
    for(i=l;i<=r;i++)a[i]=b[i];
    return ;
}
int main(){
    long long t,n,i;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        ans=0;
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        ms(1,n);
        printf("%lld\n",ans);
    }
}
