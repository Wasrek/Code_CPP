/*
    TASK:FC_Brush
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[510];
int dp[510][25][25];
int main()
{
    int n,q,i,j,k,mi,l;
    scanf("%d",&q);
    while(q--)
    {
        mi=1<<30;
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        memset(dp,127,sizeof dp);
        dp[0][0][0]=0;
        for(i=1; i<=n; i++)
        {
            for(j=0; j<=20; j++)
            {
                for(k=0; k<=20; k++)
                {
                    if(a[i]!=j && a[i]!=k)
                        continue;
                    if(a[i]==j)
                    {
                        for(l=0; l<=20; l++)
                            dp[i][j][k]=min(dp[i][j][k],dp[i-1][l][k]+(l!=j));
                    }
                    if(a[i]==k);
                    {
                        for(l=0; l<=20; l++)
                            dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][l]+(l!=k));
                    }
                    if(i==n)
                    {
                        mi=min(mi,dp[i][j][k]);
                    }
                }
            }
        }
        printf("%d\n",mi);
    }
}
