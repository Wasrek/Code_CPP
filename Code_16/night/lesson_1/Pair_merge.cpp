/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long x,y;
    bool operator<(const A  & o) const{
        if(y!=o.y) return y<o.y;
        return x<o.x;
    }
};
A a[100010];
long long inv[100010],b[100010],qs[100010];
double sum=0;
void ms(int l,int r){
    if(l==r) return ;
    int mid=(l+r)>>1;
    ms(l,mid);
    ms(mid+1,r);
    qs[l-1]=0;
    for(int i=l;i<=r;i++){
        qs[i]=qs[i-1]+inv[i];
    }
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(inv[i]<=inv[j]){
            b[k++]=inv[i++];
        }else{
            sum+=(double)((qs[mid]-qs[i-1])+inv[j]*(mid-i+1));
            b[k++]=inv[j++];
        }
    }
    while(i<=mid){
        b[k++]=inv[i++];

    }
    while(j<=r){
        b[k++]=inv[j++];
    }
    for(int i=l;i<=r;i++){
        inv[i]=b[i];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld",&a[i].x,&a[i].y);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) inv[i]=a[i].x;
    ms(1,n);
    printf("%.0lf\n",sum);
    return 0;
}