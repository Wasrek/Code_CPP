/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int dp[1010][1010][1<<3][5],sum[1010][1<<3][5],ma[5],fr[5][5]={{0,2,-1},{0,1,-1},{0,1,2,-1}};
int main()
{
    int n;
    scanf("%d %d %d %d",&n,&ma[0],&ma[1],&ma[2]);
    dp[1][1][1<<0][0]=sum[1][1<<0][0]=1;
    for(int i=2;i<=n;i++){// day
        for(int j=0;j<3;j++){// now
            for(int f=0;f<4;f++){// from
                if(fr[j][f]==-1) break;
                for(int k=1;k<(1<<3);k++){// ma
                    if(j==fr[j][f]){
                        for(int la=1;la<ma[j];la++){
                            dp[i][la+1][k][j]=dp[i-1][la][k][j];
                            dp[i][la+1][k][j]%=mod;
                            sum[i][k][j]+=dp[i][la+1][k][j];
                            sum[i][k][j]%=mod;
                        }
                    }else{
                        dp[i][1][k|(1<<j)][j]+=sum[i-1][k][fr[j][f]];
                        dp[i][1][k|(1<<j)][j]%=mod;
                        sum[i][k|(1<<j)][j]+=sum[i-1][k][fr[j][f]];
                        sum[i][k|(1<<j)][j]%=mod;
                        // printf("%d %d %d %d %d %d %d\n",i,j,fr[j][f],k,k|(1<<j),dp[i][1][k|(1<<j)][j],sum[i-1][k][fr[j][f]]);
                    }
                }
            }
        }
    }
    printf("%d\n",(sum[n][7][0]+sum[n][7][1]+sum[n][7][2])%mod);
    return 0;
}