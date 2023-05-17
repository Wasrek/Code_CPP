/*
    TASK:
    LANG: CPP
    AUTHOR: WasreK
    ALGO: DP - convex hull optimization 
    TYPE: BATCH
    SCORE: 
*/
#include<bits/stdc++.h>
using namespace std;
#define N 10010
struct A{
    long long m,c;
    bool lz;
};
long long v[N],dp[N][N];
A t[N*4];
long long f(A l,long long x){
    return l.m*x+l.c;
}
void upd(A newl,long long now,long long l,long long r){
    if(t[now].lz){
        t[now]=newl;
        t[now].lz=0;
        if(l!=r) t[now*2].lz=t[now*2].lz=1;
        return ;
    }
    if(f(newl,l)>=f(t[now],l) && f(newl,r)>=f(t[now],r)) return ;
    if(f(newl,l)<=f(t[now],l) && f(newl,r)<=f(t[now],r)){ swap(newl,t[now]); return ;}
    if(f(newl,l)>f(t[now],l)) swap(newl,t[now]);
    if(l==r) return ;
    long long mid=(l+r)>>1;
    if(f(newl,mid)>f(t[now],mid)){
        upd(newl,2*now,l,mid);
    }else{
        swap(newl,t[now]);
        upd(newl,2*now+1,mid+1,r);
    }
    return ;
}
long long qy(long long x,long long now,long long l,long long r){
    if(t[now].lz){
        return 2e9;
    }
    long long ans=f(t[now],x);
    if(l==r) return ans;
    long long mid=(l+r)>>1;
    if(x<=mid){
        return min(ans,qy(x,now*2,l,mid));
    }else{
        return min(ans,qy(x,now*2+1,mid+1,r));
    }
}
int main()
{
    long long n,k,ma=0;
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&v[i]);
        // dp[1][i]=pow((v[i]-v[1]),2.0);
        dp[1][i]=(v[i]-v[1])*(v[i]-v[1]);
        ma=max(ma,v[i]);
    }
    for(long long i=2;i<=k;i++){
        for(long long j=i;j<=n;j++){
            upd({-2*v[j],dp[i-1][j-1]+v[j]*v[j]},1,1,ma);
            dp[i][j]=qy(v[j],1,1,ma)+v[j]*v[j];
            // printf("%d %d %d %d\n",i,j,qy(v[j],1,1,ma),dp[i][j]);
        }
        t[1].lz=1;
    }
    printf("%lld\n",dp[k][n]);
    return 0;
}