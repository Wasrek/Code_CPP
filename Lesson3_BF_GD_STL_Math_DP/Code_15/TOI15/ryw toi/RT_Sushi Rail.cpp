/*
    TASK:RT_Sushi Rail
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long seg[400008],num[100008];
void build(int l,int r,int now){
    if(l==r){
        seg[now]=num[l]; return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    seg[now]=(seg[now*2]*seg[now*2+1])%mod;
}
long long query(int l,int r,int now,int ll,int rr){
    if(rr<l || r<ll) return 1;
    if(ll<=l && r<=rr) return seg[now];
    int mid=(l+r)>>1;
    return (query(l,mid,now*2,ll,rr)*query(mid+1,r,now*2+1,ll,rr))%mod;
}
long long dp[18][100008];
int main(){
    int n,i,j;
    long long ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%lld",&num[i]),dp[1][i]=num[i],ans=max(ans,num[i]);
    build(1,n,1);
    for(i=2;i<=16;i++){
        long long ma=0;
        for(j=(1<<i)-1;j<=n;j++){
            ma = max(ma,dp[i-1][j-(1<<(i-1))]);//push max
            dp[i][j] = query(1,n,1,j-(1<<(i-1))+1,j)+ma;
            ans=max(ans,dp[i][j]);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
