/*
    TASK:Miners
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
int dp[maxn][4][4][4][4],a[maxn];
char str[maxn];
int dif(int i,int j,int k)
{
    int sum=0;
    if(i==1 || j==1 || k==1)
        sum++;
    if(i==2 || j==2 || k==2)
        sum++;
    if(i==3 || j==3 || k==3)
        sum++;
    return sum;
}
int main()
{
    int n,i,j,k,l,m,ans=-1;
    scanf("%d %s",&n,str+1);
    for(i=1; i<=n; i++)
    {
        if(str[i]=='M')
            a[i]=1;
        else if(str[i]=='F')
            a[i]=2;
        else if(str[i]=='B')
            a[i]=3;
    }
    for(i=1; i<=n; i++)
    {
        for(j=0; j<4; j++)
        {
            for(k=0; k<4; k++)
            {
                for(l=0; l<4; l++)
                {
                    for(m=0; m<4; m++)
                    {
                        dp[i][j][k][l][m]=-1<<30;
                    }
                }
            }
        }
    }
    dp[1][0][a[1]][0][0]=dp[1][0][0][0][a[1]]=1;
    for(i=2; i<=n; i++)
    {
        for(j=0; j<4; j++)
        {
            for(k=0; k<4; k++)
            {
                for(l=0; l<4; l++)
                {
                    for(m=0; m<4; m++)
                    {
                        dp[i][k][a[i]][l][m]=max(
                                                 dp[i][k][a[i]][l][m],
                                                 dp[i-1][j][k][l][m]+dif(j,k,a[i]));
                        dp[i][j][k][m][a[i]]=max(
                                                 dp[i][j][k][m][a[i]],
                                                 dp[i-1][j][k][l][m]+dif(l,m,a[i]));
                    }
                }
            }
        }
    }
    for(j=0; j<4; j++)
    {
        for(k=0; k<4; k++)
        {
            for(l=0; l<4; l++)
            {
                for(m=0; m<4; m++)
                {
                    ans=max(ans,dp[n][j][k][l][m]);
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
6
MBMFFB
16
MMBMBBBBMMMMMBMB
*/
