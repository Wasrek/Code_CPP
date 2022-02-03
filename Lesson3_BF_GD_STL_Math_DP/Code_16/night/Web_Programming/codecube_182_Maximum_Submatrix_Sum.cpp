/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100],b[100100];
int main()
{
    long long n,h,w,ch,cw,now;
    ch=cw=0;
    scanf("%lld %lld %lld",&n,&h,&w);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }//choose h * w
    for(int i=h;i<=n;i++){
        ch=max(ch,a[i]-a[i-h]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&b[i]);
        b[i]+=b[i-1];
    }//choose w * h
    for(int i=w;i<=n;i++){
        cw=max(cw,b[i]-b[i-w]);
    }
    printf("%lld\n",(ch*w)+(cw*h));
    return 0;
}