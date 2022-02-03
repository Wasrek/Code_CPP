/*
    TASK:NC_Queue of Soldiers
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
map<long long,long long>mp;
map<long long,long long> ::iterator it;
long long pas[50010][1010],dp[105][1005];
int main(){
    long long i,j,n,k,l,num,cntpeo,run,peo,star,bar;
    pas[0][0]=1;
    for(i=1; i<=50000; i++)
    {
        for(j=0; j<=i&&j<=1000; j++)
        {
            pas[i][j]=pas[i-1][j];
            if(j) pas[i][j]+=pas[i-1][j-1],pas[i][j]%=mod;
        }
    }
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%lld",&num);
        mp[num]++;
    }
    dp[0][0]=1;
    cntpeo=0;
    for(it=mp.begin(),run=0;it!=mp.end();it++){
        run++;
        for(j=0;j<=k;j++){
            peo=it->second;
            for(l=0;l<=peo;l++){
                if(l>j){
                    break;
                }
                if(!cntpeo && j){
                    break;
                }
                star=l;
                bar=max(0ll,cntpeo-1);
                dp[run][j]+=dp[run-1][j-l]*pas[star+bar][min(star,bar)];
                dp[run][j]%=mod;
            }
        }
        cntpeo+=it->second;
    }
    printf("%lld\n",dp[run][k]);
    return 0;
}
