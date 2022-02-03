/*
    TASK:Maximum Submatrix Sum
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010];
int main(){
    long long n,h,w,i,maa=0,mab=0,ans;
    scanf("%lld %lld %lld",&n,&h,&w);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
        if(i>=h){
            maa=max(maa,a[i]-a[i-h]);
        }else maa=max(maa,a[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&b[i]);
        b[i]+=b[i-1];
        if(i>=w){
            mab=max(mab,b[i]-b[i-w]);
        }else mab=max(mab,b[i]);
    }
    //printf("%lld %lld\n",maa,mab);
    ans=(maa*w)+(mab*h);
    printf("%lld\n",ans);
    return 0;
}
