/*
    TASK:Pair
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,b;
    bool operator<(const A & o) const{
        if(b!=o.b) return b<o.b;
        else return a<o.a;
    }
};
A a[100010];
int m[100010],qs[100010],h[100010];
long long sum=0,cou=0;
void ms(int l,int r){
    if(l>=r) return ;
    int mid=(l+r)/2;
    ms(l,mid);
    ms(mid+1,r);
    qs[l]=m[l];
    for(int i=l+1;i<=r;i++){
        qs[i]=qs[i-1]+m[i];
    }
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(m[i]<=m[j]){
            h[k++]=m[i];
            i++;
        }else{
            sum+=(qs[mid]-qs[i-1]);
            sum+=(mid-i+1)*m[j];
            h[k++]=m[j];
            j++;
        }
    }
    while(i<=mid){
        h[k++]=m[i];
        i++;
    }
    while(j<=r){
        h[k++]=m[j];
        j++;
    }
    for(int i=l;i<=r;i++){
        m[i]=h[i];
    }
    return ;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i].a,&a[i].b);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        m[i]=a[i].a;
    }
    ms(1,n);
    printf("%lld\n",sum);
    printf("%d\n",cou);
    return 0;
}