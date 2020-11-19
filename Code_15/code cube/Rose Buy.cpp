/*
    TASK:Rose Buy
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000100],qs[1000100];
int main(){
    long long n,k,i;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        qs[i]=qs[i-1]+a[i];
        if(a[i]<0)qs[i]=0;
    }

}
