/*
    TASK:Stirling
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int main(){
    dp[1][1]=1;
    int i,j;
    for(i=2;i<=1000;i++){
        for(j=1;j<=i;j++){
            dp[i][j]=(dp[i-1][j-1]+(dp[i-1][j]*j));
        }
    }
    int q,a,b;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&b);
        printf("%d\n",dp[a][b]);
    }
}
