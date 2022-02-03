/*
    TASK:RT_Sweet
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main(){
    long long l,r,mid,n,m,i,sum=0,ma=0,mi;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        ma=max(ma,a[i]);
        sum+=a[i];
    }
    if(sum%n==0)mi=sum/n;
    else mi=sum/n+1;
    l=mi,r=ma;
    while(l<r){
        mid=(l+r)/2;
        sum=0;
        for(i=1;i<=n;i++){
            if(a[i]>mid)
            sum+=(a[i]-mid);
        }
        if(sum>m)l=mid+1;
        else r=mid;
    }
    printf("%lld\n",l);
}
