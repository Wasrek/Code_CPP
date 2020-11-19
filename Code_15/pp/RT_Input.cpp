/*
    TASK:RT_Input
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 9901
int dp[1005][1005],a[1005],b[1005];
int main()
{
    int q,n,m;
    scanf("%d",&q);
    dp[1][0]=1;
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
            dp[i][j]%=mod;
        }
    }
    while(q--)
    {
        int ans=1,num;
        scanf("%d %d",&n,&m);
        int idx=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num);
            while(num>0)
            {
                a[idx++]=i;
                num--;
            }
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&b[i]);
        }
        b[m+1]=idx-1;
        b[0]=1;
        for(int i=1;i<=m+1;i++)
        {
            int num1=a[b[i]];
            int num2=a[b[i-1]];
            ans*=dp[num1-num2+1][b[i]-b[i-1]];
            //printf(">%d\n",num1-num2+1);
            ans%=mod;
        }
        printf("%d\n",ans);
    }
}
