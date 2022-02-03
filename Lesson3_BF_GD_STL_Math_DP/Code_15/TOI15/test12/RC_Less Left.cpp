/*
    TASK:RC_Less Left
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main(){
    long long n,i,mi=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        mi=max(mi,a[i]);
        a[i]+=a[i-1];
//        printf("%lld\n",a[i]);
    }
//    for(i=1;i<=n;i++)printf("%lld ",a[i]);
//    printf("\n");
    for(i=2;i<=n;i++){
        if(a[i-1]==(a[n]-a[i])){mi=min(mi,a[i]);}
//        printf("%lld %lld\n",a[i-1],a[n]-a[i]);
    }
    for(i=2;i<=n;i++){
        if(a[i]-a[1]==a[n]-a[i]){mi=min(mi,a[1]);}
//        printf("1: %lld %lld\n",a[i]-a[1],a[n]-a[i]);
    }
    for(i=1;i<n;i++){
        if(a[i]==a[n-1]-a[i]){mi=min(mi,a[n]);}
//        printf("2: %lld %lld\n",a[i],a[n-1]-a[i]);
    }
    a[n]-=mi;
    a[n]/=2;
    printf("%lld\n",mi+a[n]);
}
/*
4
4 5 8 13
*/
