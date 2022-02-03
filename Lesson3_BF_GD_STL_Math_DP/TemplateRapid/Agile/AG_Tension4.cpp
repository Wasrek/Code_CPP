#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,q,s,t,l,r,i,j,mid,ans;
    scanf("%lld %lld",&n,&q);
    while(q--){
        scanf("%lld %lld",&s,&t);
        ans=0;
        l=0,r=1000000001;
        while(l<r){
            mid=(l+r+1)/2;
            if(mid*mid>t) r=mid-1;
            else l=mid;
        }
        ans+=l;
        l=-1,r=1000000001;
        while(l<r){
            mid=(l+r+1)/2;
            if(mid*mid>s-1) r=mid-1;
            else l=mid;
        }
        ans-=l;
        l=0,r=1000000001;
        while(l<r){
            mid=(l+r+1)/2;
            if(2*mid*mid>t) r=mid-1;
            else l=mid;
        }
        ans+=l;
        l=-1,r=1000000001;
        while(l<r){
            mid=(l+r+1)/2;
            if(2*mid*mid>s-1) r=mid-1;
            else l=mid;
        }
        ans-=l;
        printf("%lld\n",ans);
    }
return 0;
}
