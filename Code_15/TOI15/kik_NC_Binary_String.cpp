// this code isn't perfect yet, still bugged
#include<bits/stdc++.h>
using namespace std;
int h[35][1<<21],y,dp[100005];
char a[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf(" %s",a);
        y=0;
        int lena=strlen(a);
        for(int j=lena-1;j>=0;j--)
        {
            y*=2;
            y+=a[j]-'0';
        }
        h[lena][y]=1;
    }
    scanf(" %s",a+1);
    int len=strlen(a+1);
    dp[0]=1;
    for(int i=1;i<=len;i++)
    {
        y=0;
        for(int j=i;j>=1 && i-j<20 ;j--)
        {
            y*=2;
            y+=a[j]-'0';
            if(h[i-j+1][y]==1)
            {
                dp[i]+=dp[i-j];
                printf("i %d j %d : %d\n",i,j,dp[i]);
                dp[i]%=1000000007;
            }
        }
    }
    printf("%d\n",dp[len]);
}
