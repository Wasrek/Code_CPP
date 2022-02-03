/*
    TASK:Miners
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100100
char s[N];
int a[N];
long long dp[N][4][4][4][4];
int val(int i,int j,int k){
    int sum=0;
    if(i==1 || j==1 || k==1) sum++;
    if(i==2 || j==2 || k==2) sum++;
    if(i==3 || j==3 || k==3) sum++;
    return sum;
}
int main()
{
    int n;
    scanf("%d",&n);
    scanf(" %s",s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='M')a[i]=1;
        if(s[i]=='B')a[i]=2;
        if(s[i]=='F')a[i]=3;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                for(int l=0;l<4;l++){
                    for(int m=0;m<4;m++){
                        dp[i][j][k][l][m]=-(1<<30);
                    }
                }
            }
        }
    }
    long long ans=0;
    dp[1][0][a[1]][0][0]=dp[1][0][0][0][a[1]]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                for(int l=0;l<4;l++){
                    for(int m=0;m<4;m++){
                        dp[i][k][a[i]][l][m]=max(dp[i][k][a[i]][l][m],dp[i-1][j][k][l][m]+val(j,k,a[i]));
                        dp[i][j][k][m][a[i]]=max(dp[i][j][k][m][a[i]],dp[i-1][j][k][l][m]+val(l,m,a[i]));
                        if(i==n){
                            ans=max(ans,max(dp[i][k][a[i]][l][m],dp[i][j][k][m][a[i]]));
                        }
                    }
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}