/*
    TASK:RC_WingPhlad
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010];
long long gcd(long long aa,long long b){
    if(aa%b==0)return b;
    return gcd(b,aa%b);
}
int main(){
    long long q,n,m,i,j,sum,mm,ma,g;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&n,&m);
        scanf("%lld",&a[1]);
        g=a[1];
        for(i=1;i<n;i++){
            scanf("%lld",&a[i]);
            g=gcd(g,a[i]);
        }
        printf("%lld",m-g);
    }
}
