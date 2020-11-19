/*
    TASK:Farm tank
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long t[100100];
int main(){
    long long n,m,i,l,r,mid,sum;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++){
        scanf("%lld",&t[i]);
    }
    l=0,r=2000000000000000;
    while(l<r){
        mid=(l+r)/2;
        sum=0;
        for(i=0;i<n;i++){
            sum+=mid/t[i];
        }
        if(sum>=m)r=mid;
        else l=mid+1;
    }
    printf("%lld\n",l);
    return 0;
}
