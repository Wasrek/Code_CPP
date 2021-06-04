/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 110
#define MOD 1000000007
long long dp[N][N][N];
int pre[N],in[N],mp[N];
long long recur(int inl,int inr,int pt){
    if(dp[inl][inr][pt]) return dp[inl][inr][pt]%MOD;
    if(inl>inr) return 1;
    if(pre[pt]>inr || pre[pt]<inl) return 0;
    //root = pre[pt]
    long long le=recur(inl,pre[pt]-1,pt+1),mi,ri;
    for(int i=pre[pt];i<=inr;i++){
        mi=recur(pre[pt]+1,i,pt+(pre[pt]-inl)+1);
        ri=recur(i+1,inr,pt+(i-inl)+1);
        dp[inl][inr][pt]+=(le*mi*ri)%MOD;
        dp[inl][inr][pt]%=MOD; 
    }
    return dp[inl][inr][pt]%MOD;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&pre[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&in[i]);
        mp[in[i]]=i;
    }
    for(int i=1;i<=n;i++){
        pre[i]=mp[pre[i]];
    }
    for(int i=1;i<=n;i++){
        mp[pre[i]]=i;
    }
    printf("%lld",recur(1,n,1));
    return 0;
}