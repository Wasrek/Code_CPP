/*
    TASK:RT_Rabbit_Hole
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,s,now,sum;
    scanf("%ld %lld",&n,&s);
    long long l=0,r=n+1;
    while(l<r){
        long long mid=(l+r)/2;
        now=mid;
        sum=0;
        while(now>0){
            sum+=now%10;
            now/=10;
        }
        if(mid-sum>=s) r=mid;
        else l=mid+1;
    }
    if(l>n){
        printf("0\n-1\n");
    }else printf("%lld\n%lld\n",n-l+1,n);
    return 0;
}