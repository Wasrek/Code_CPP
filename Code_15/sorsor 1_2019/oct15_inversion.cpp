/*
    TASK:Inversion
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100],b[100100],ans=0;
void ms(int l,int r){
    if(l==r) return ;
    int mid=(l+r)>>1;
    ms(l,mid);
    ms(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            b[k++]=a[i++];
        }else{
            b[k++]=a[j++];
            ans+=mid-i+1;
        }
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
    return ;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    ms(0,n-1);
    printf("%lld",ans);
}