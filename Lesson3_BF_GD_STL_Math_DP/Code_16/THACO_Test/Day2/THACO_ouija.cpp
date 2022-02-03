/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long dp[500][500],a[500][500],b[500][500];
int main()
{
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2; i<=500; i++)
    {
        for(int j=0; j<=500; j++)
        {
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%1000000007;
        }
    }
    // for(int i=1;i<=5;i++){
    //     for(int j=0;j<=5;j++){
    //         printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    long long n,m,x,y;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i<=1 || j<=1){
                a[i][j]=1;
                continue;
            }
            x=i-1,y=j;
            a[i][j]=((dp[x+y-2][x-1]*dp[x+y-2][x-1])%mod);
            x=i,y=j-1;
            a[i][j]=((a[i][j]+((dp[x+y-2][x-1]*dp[x+y-2][x-1])%mod))%mod);
        }
    }
    a[1][1]=0;
    // for(int i=1;i<=5;i++){
    //     for(int j=1;j<=5;j++){
    //         printf("%d ",a[i][j]);
    //     }
    //     printf("\n");
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[i][j]=a[i][j];
            for(int ii=1;ii<=i-1;ii++){
                for(int jj=1;jj<=j-1;jj++){
                    if(ii==1 && jj==1) continue;
                    b[i][j]+=((a[ii][jj]*b[i-ii+1][j-jj+1])%mod);
                    b[i][j]%=mod;
                }
            }
            x=i,y=j;
            // printf("-%d ",dp[x+y-2][x-1]*dp[x+y-2][x-1]);
            b[i][j]=(((((dp[x+y-2][x-1]*dp[x+y-2][x-1])%mod)-b[i][j])+(2*mod))%mod);
        }
        // printf("\n");
    }
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            printf("%lld ",b[i][j]);
        }
        printf("\n");
    }
    printf("%lld\n",b[n][m]%mod);
}