#include<bits/stdc++.h>
using namespace std;
map<long long,long long>mp;
map<long long,long long>::iterator it;
long long dp[105][1005];
long long pas[50100][1200];
#define mod 1000000007
int main()
{
    long long n,k,i,j,num,run,cntpeo=0,l;
    pas[0][0]=1;
    dp[0][0]=1;
    for(i=1; i<=50000; i++)
    {
        for(j=0; j<=i&&j<=1000; j++)
        {
            pas[i][j]=pas[i-1][j];
            if(j) pas[i][j]+=pas[i-1][j-1],pas[i][j]%=mod;
        }
    }
    scanf("%lld %lld",&n,&k);
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&num);
        mp[num]++;
    }
    for(it=mp.begin(),run=0; it!=mp.end(); it++)
    {
        run++;
        for(j=0; j<=k; j++)
        {
            long long peo=it->second;
            for(l=0; l<=peo; l++)
            {
                if(l>j)
                    break;
                if(!cntpeo&&j)
                    break;
                long long star=l,bar=max(0ll,cntpeo-1);
                dp[run][j]+=dp[run-1][j-l]*pas[star+bar][min(star,bar)];
                dp[run][j]%=mod;
            }
        }
        cntpeo+=it->second;
    }
    printf("%lld",dp[run][k]);
    return 0;
}
