/*
    TASK:Pedigree
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long c[25];
long long f(long long lvl,long long w){
    long long now=w*2-c[lvl]+1,a,b;
    if(w<=0)return -1;
    if(lvl==1){
        return w;
    }
    long long n=now/2;
    a=f(lvl-1,n);
    b=f(lvl-1,now-n);
//    printf("%lld %lld %lld %lld %lld\n",lvl,w,a,now,n);
    if(a==-1){
        return -1;
    }else
    return a+b;
}
int main(){
    long long n,w,ans,q;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&n,&w);
        for(int i=2;i<=n;i++){
            scanf("%lld",&c[i]);
        }
        ans=f(n,w);
        if(ans<=0)ans=-1;
        printf("%lld\n",ans);
    }
}