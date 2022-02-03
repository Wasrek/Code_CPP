/*
    TASK:NC_Collect Point
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main(){
    long long n,m,i,ma=0,k,l,now;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]>m)a[i]%=m;
        ma=max(ma,a[i]);
        a[i]+=a[i-1];
        if(a[i]>m)a[i]%=m;
        ma=max(ma,a[i]);
    }
    for(k=2;k<=n;k++){
        for(i=2;i<=n-k+1;i++){
            now=a[i+k-1]-a[i-1];
            while(now<0){
                now+=m;
                now%=m;
            }
            //printf("%d\n",now);
            ma=max(ma,now);
        }
    }
    printf("%lld\n",ma);
    return 0;
}
