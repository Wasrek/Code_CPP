#include<bits/stdc++.h>
using namespace std;
struct A{
    long long a,b;
    bool operator<(const A&o)const{
        if(a!=o.a)return a<o.a;
        else return b<o.b;
    }
};
A a[100010];
long long m[100010],qs[100010],ans=0,b[100010],n;
void ms(long long l,long long r){
    if(l==r)return ;
    long long mid=(l+r)/2,i,j,k;
    ms(l,mid);
    ms(mid+1,r);
    qs[l-1]=0;
    for(i=l;i<=r;i++){
        qs[i]=qs[i-1]+m[i];
    }
    i=l;
    j=mid+1;
    k=l;
    while(i<=mid && j<=r){
        if(m[i]<=m[j]){
            b[k++]=m[i++];
        }
        else{
            ans+=(qs[mid]-qs[i-1]+(mid-i+1)*m[j]),b[k++]=m[j++];
        }
    }
    while(i<=mid){
        b[k++]=m[i++];
    }
    while(j<=r){
        b[k++]=m[j++];
    }
    for(i=l;i<=r;i++){
        m[i]=b[i];
    }
}
int main(){
    long long i;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&a[i].b,&a[i].a);
    }
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++){
        m[i]=a[i].b;
    }
    ms(1,n);
    printf("%lld",ans);
    return 0;
}