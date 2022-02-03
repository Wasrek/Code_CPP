/*
    TASK:PT_Big_Pom
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long w[100010],r,s,c;
long long bomb(long long nl,long long nr){
    long long lb,ub;
    lb=lower_bound(w+1,w+1+c,nl)-w;
    ub=upper_bound(w+1,w+1+c,nr)-w;
    long long k=ub-lb;
    if(!k) return r;
    if(nl==nr){
        if(!k){
            return r;
        }else{
            return (nr-nl+1)*k*s;
        }
    }
    long long mid=(nl+nr)/2;
    long long ml=bomb(nl,mid);
    long long mr=bomb(mid+1,nr);
    long long now;
    if(k)now=(nr-nl+1)*k*s;
    else now=r;
    return min((ml+mr),now);
}
int main()
{
    long long q,n,ans;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld %lld %lld",&n,&c,&r,&s);
        for(long long i=1;i<=c;i++){
            scanf("%d",&w[i]);
        }
        sort(w+1,w+1+c);
        ans=bomb(1,(1<<n));
        printf("%lld\n",ans);
    }
    return 0;
}