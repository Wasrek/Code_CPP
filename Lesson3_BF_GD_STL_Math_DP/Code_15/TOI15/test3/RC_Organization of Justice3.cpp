/*
    TASK:RC_Organization of Justice3
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
struct A{
    long long a[210][210];
};
A ans,dp[33],tmp;
void mul(A *a,A *b){
    long long i,j,l;
    memset(tmp.a,0,sizeof tmp.a);
    for(i=0;i<202;i++){
        for(j=0;j<202;j++){
            tmp.a[i][j]=0;
            for(l=0;l<202;l++){
                tmp.a[i][j]+=a->a[i][l]*b->a[l][j];
                tmp.a[i][j]%=mod;
            }
        }
    }
}
int main(){
    long long i,j,n,k;
    dp[0].a[0][0]=1;
    for(i=1;i<=200;i++){
        dp[0].a[i][0]=1;
        for(j=1;j<=i;j++){
            dp[0].a[i][j]=(dp[0].a[i-1][j]+dp[0].a[i-1][j-1])%mod;
        }
    }
    scanf("%lld %lld",&n,&k);
    dp[0].a[201][201]=dp[0].a[201][k]=1;
    for(i=1;i<30;i++){
        mul(&dp[i-1],&dp[i-1]);
        dp[i]=tmp;
    }
    for(i=0;i<=200;i++){
        ans.a[i][0]=1;
    }
    for(i=0;i<30;i++){
        if((1ll<<i)&n){
            mul(&dp[i],&ans);
            ans=tmp;
        }
    }
    printf("%lld\n",ans.a[201][0]);
}
