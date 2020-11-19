/*
    TASK:FC_Coalition
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,n;
    bool operator<(const A &o)const{
        return n>o.n;
    }
};
int a[300010],w[300010];
A b[300010];
int main(){
    int n,i,r,l,sum=0,mid,now;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]={i,a[i]};
        sum+=a[i];
    }
    sum/=2;
    sum+=1;
    sort(b+1,b+1+n);
    for(i=1;i<=n;i++){
        b[i].n+=b[i-1].n;
        w[b[i].i]=i;
    }
    for(i=1;i<=n;i++){
    l=1;r=n;
    while(l<r){
        mid=(l+r)/2;
        now=b[mid].n;
        if(w[i]<=mid){
        now-=a[i];
        }
        if(now+a[i]>=sum){
        r=mid;
        }else{
            l=mid+1;
        }
    }
    if(l>=w[i])l--;
    printf("%d ",l);
    }
    return 0;
}
