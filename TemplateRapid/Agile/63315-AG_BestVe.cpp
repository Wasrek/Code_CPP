#include<bits/stdc++.h>
using namespace std;
int s[100],v[100],dp[3][6000][100];
int main(){
    int q,n,kk,l,i,j,k,m;
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d",&n,&kk,&l);
        for(i=1;i<=n;i++){
            scanf("%d",&s[i]);
            v[i]=i-1;
        }
        m=min(l,5000);
        m+=((kk-1)*kk)/2;
        memset(dp,-127,sizeof dp);
        for(j=0;j<=m;j++){
            dp[0][j][0]=0;
            dp[1][j][0]=0;
        }
        for(i=1;i<=n;i++){
            for(j=0;j<=m;j++){
                for(k=1;k<=kk;k++){
                    if(j<v[i])dp[i%2][j][k]=dp[(i+1)%2][j][k];
                    else{
                        if(dp[(i+1)%2][j][k]>dp[(i+1)%2][j-v[i]][k-1]+s[i])dp[i%2][j][k]=dp[(i+1)%2][j][k];
                        else dp[i%2][j][k]=dp[(i+1)%2][j-v[i]][k-1]+s[i];
                    }
                }
            }
        }
        printf("%d\n",dp[n%2][m][kk]);
    }
    return 0;
}
/*
2
5 2 3
60 54 32 95 93
5 1 1
1 2 100 200 300
*/
