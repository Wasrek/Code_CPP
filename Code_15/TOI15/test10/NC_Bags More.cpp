/*
    TASK:NC_Bags More
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long w,v;
    bool operator<(const A&o)const{
    return w<o.w;
    }
};
A a[300010];
int b[300010];
priority_queue<long long> h;
int main(){
    long long sum=0,n,aa,i;
    scanf("%lld %lld",&n,&aa);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&a[i].w,&a[i].v);
    }
    a[n+1].w=1<<30;
    sort(a+1,a+1+n);
    for(i=1;i<=aa;i++)scanf("%lld",&b[i]);
    sort(b+1,b+1+aa);
//    printf("%lld\n",aa);
    long long j=1,cnt=0;
    for(i=1;i<=n;i++){
        if(a[i].w<=b[j])h.push(a[i].v);
        while(a[i+1].w>b[j] && j<=aa){if(!h.empty())sum+=h.top(),h.pop();j++;}
        //printf("%lld\n",j);
        if(j>aa)break;
    }
    //printf("%lld\n",j);
    aa-=j;
    aa+=1;
    //printf("%lld\n",aa);
    while(aa-- && !h.empty())sum+=h.top(),h.pop();
    printf("%lld\n",sum);
}
/*
3 2
1 3
5 2
2 5
8
2
*/
