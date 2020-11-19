#include<bits/stdc++.h>
using namespace std;
vector <int> pa[500005];
int dp[500005],sum[500005];
int main()
{
    int q,n,i,j;
    for(i=2;i<=500000;i++)
    {
        if(sum[i])
            continue ;
        for(j=i;j<=500000;j+=i)
        {
            sum[j]+=i;
            pa[j].push_back(i);
        }
    }
    dp[0]=1;
    for(i=1;i<=500000;i++)
    {
        for(auto x : pa[i])
            dp[i]|=(1^dp[sum[i]-x]);
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        if(dp[n])
            printf("1\n");
        else
            printf("2\n");
    }
    return 0;
}
