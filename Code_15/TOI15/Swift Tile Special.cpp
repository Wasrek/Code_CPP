#include<bits/stdc++.h>
using namespace std;
int dp[120][120];
int main(){
    int q,n,k,i,j;
    for(j=0;j<=100;j++){
        dp[0][j]=1;
        for(i=1;i<=100;i++){
            dp[i][j]+=dp[i-1][j]%9241;
            if(i>=2)dp[i][j]+=dp[i-2][j]%9241;
            if(i>=2 && j>=1)dp[i][j]+=dp[i-2][j-1]%9241;
            if(i>=3 && j>=2){
                for(k=3;k<=i;k++){
                    dp[i][j]+=(dp[i-k][j-2]*2)%9241;
                }
            }
            dp[i][j]%=9241;
        }
	}
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        printf("%d\n",dp[n][k]);
    }
}
