#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int dp[100005];
char a[100005];
int mem[25][1<<21];
int main()
{
    int n,i,len,j,num;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf(" %s",a);
        len=strlen(a);
        num=0;
        for(j=0;j<len;j++)
        {
            num*=2;
            num+=a[j]-'0';
        }
        mem[len][num]=1;
    }
    scanf(" %s",&a[1]);
    len=strlen(&a[1]);
    dp[0]=1;
    for(i=1;i<=len;i++)
    {
        num=0;
        for(j=i-19;j<=i;j++)
        {
            if(j<=0)
                continue ;
            num*=2;
            num+=a[j]-'0';
        }
        for(j=1;j<=20;j++)
        {
            if(i-j<0)
                continue ;
            if(mem[j][num&((1<<j)-1)])
            {
                dp[i]+=dp[i-j];
                dp[i]%=mod;
            }

        }
        //printf(">>%d %d %d\n",i,num,dp[i]);
    }
    printf("%d",dp[len]);
    return 0;
}
