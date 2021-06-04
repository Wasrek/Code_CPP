/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[40100][110],qs[40100];
void dc(int l,int r,int optl,int optr,int st){
    if(l>r) return ;
    int mid=(l+r)>>1,opt;
    dp[mid][st]=__LONG_LONG_MAX__;
    for(int i=optl;i<=min(mid,optr);i++){
        if(dp[mid][st]>dp[i][st-1]+(qs[mid]-qs[i])*(mid-i)){
            dp[mid][st]=dp[i][st-1]+(qs[mid]-qs[i])*(mid-i);
            opt=i;
        }
    }
    dc(l,mid-1,optl,opt,st);
    dc(mid+1,r,opt,optr,st);
}
int main()
{
    long long n,m;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&qs[i]);
        qs[i]+=qs[i-1];
        dp[i][0]=qs[i]*i;
    }
    for(int j=1;j<=m;j++) dc(1,n,1,n,j);
    printf("%lld\n",dp[n][m]);
    return 0;
} 
