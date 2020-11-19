/*
    TASK:NC_Bags More
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int w,v;
    bool operator<(const A&o)const{
    if(v!=o.v) return v>o.v;
    return w>o.w;
    }
};
A a[300010];
int b[300010];
int main(){
    int n,aa,i;
    long long sum=0;
    scanf("%d %d",&n,&aa);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a[i].w,&a[i].v);
    }
    sort(a+1,a+1+n);
    for(i=1;i<=aa;i++)scanf("%d",&b[i]);
    sort(b+1,b+1+aa,greater<int>());
    int j=1;
    for(i=1;i<=n;i++){
        if(a[i].w<=b[j])sum+=a[i].v,j++;
        if(j>aa)break;
    }
    printf("%lld",sum);
}
