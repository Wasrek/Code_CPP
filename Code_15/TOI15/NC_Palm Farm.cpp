/*
    TASK:NC_Palm Farm
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[110][110],mark[110][110][6010],num[110][110][3],dp[110][110][6010];
int main(){
    int n,m,i,j,k,temp;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            temp=a[i][j];
            if(temp==0)continue;
            while(temp%2==0){
                temp/=2;
                num[i][j][0]++;
            }
            while(temp%7==0){
                temp/=7;
                num[i][j][1]++;
            }
            dp[i][j][num[i][j][0]]=num[i][j][1];
            mark[i][j][num[i][j][0]]=1;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            for(k=0;k<=6000;k++){
                if(mark[i-1][j][k]){
                    dp[i][j][k+num[i][j][0]] = max(dp[i][j][k+num[i][j][0]],dp[i-1][j][k]+num[i][j][1]);
                    mark[i][j][k+num[i][j][0]] = 1;
                }
                if(mark[i][j-1][k]){
                    dp[i][j][k+num[i][j][0]] = max(dp[i][j][k+num[i][j][0]],dp[i][j-1][k]+num[i][j][1]);
                    mark[i][j][k+num[i][j][0]] =1;
                }
            }
        }
    }
    int ans=0;
    for(i=0;i<=6000;i++){
        ans=max(ans,min(i,dp[n][m][i]));
    }
    printf("%d\n",ans);
}
