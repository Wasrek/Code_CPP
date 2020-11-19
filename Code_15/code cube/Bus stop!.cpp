/*
    TASK:Bus stop!
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100];
long long gcd(long long i,long long j){
    if(i%j==0)return j;
    return gcd(j,i%j);
}
int main(){
    long long n,m,ans,i;
    scanf("%lld %lld",&n,&a[1]);
    ans=a[1];
    for(i=2;i<=n;i++){
        scanf("%lld",&a[i]);
        ans=ans*a[i]/gcd(ans,a[i]);
    }
    printf("%lld\n",ans);
}
