/*
    TASK:Anyway
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010],mark[1010][1010];
int main()
{
    int n,m,a,b,i,j,d;
    scanf("%d %d %d",&n,&m,&d);
    n++,m++;
    while(d--){
        scanf("%d %d",&a,&b);
        mark[a+1][b+1]=2;
    }
    dp[1][1]=1;
    for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
        if(mark[i][j]==2)
        dp[i][j]=0;
        else{
            dp[i][j]+=(dp[i-1][j]+dp[i][j-1])%1000000;
        }
    }
    }
    printf("%d\n",dp[n][m]%1000000);

    return 0;
}
