/*
    TASK:Matrixchain
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int row[20],col[20],dp[20][20],path[20][20];
void prin(int l,int r)
{
    if(l==r)
    {
        printf("A%d",l+1);
        return ;
    }
    printf("(");
    prin(l,path[l][r]);
    printf(" x ");
    prin(path[l][r]+1,r);
    printf(")");
}
int main()
{
    int n,i,j,k,m,mi,now;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d %d",&row[i],&col[i]);
    for(m=1; m<n; m++)
    {
        for(i=0; i<n-m; i++)
        {
            j=i+m;
            mi=1<<30;
            for(k=i; k<j; k++)
            {
                now = dp[i][k]+dp[k+1][j]+row[i]*col[k]*col[j];
                if(now<mi)
                    mi=now,path[i][j]=k;
            }
            dp[i][j]=mi;
        }
    }
    printf("%d\n",dp[0][n-1]);
    prin(0,n-1);
    return 0;
}
