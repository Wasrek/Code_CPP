/*
    TASK:53Upgrade
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long mo(long long a,long long b,long long c){
    if(b==1)return a%c;
    long long n=mo(a,b/2,c);
    if(b%2==0)return (n*n)%c;
    if(b%2==1)return (n*n*a)%c;
}
int main(){
    long long sum,q,i,n,m,mod,k;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld %lld",&n,&m,&mod);
        k=(n+1)*n/2;
        if(n>=1000000)k=(999999ll+1)*999999/2;
        k%=mod;
        //printf("%d\n",k);
        printf("%lld\n",mo(k,m,mod));
    }
}
