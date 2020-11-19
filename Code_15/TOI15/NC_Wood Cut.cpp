/*
    TASK:NC_Wood Cut
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010];
long long gcd(long long a,long long b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}
int main(){
    long long n,i,ans=0;
    scanf("%lld",&n);
    a[0]=1;
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        ans+=(a[i]-gcd(a[i],a[i-1]));
    }
    printf("%lld",ans);
}
