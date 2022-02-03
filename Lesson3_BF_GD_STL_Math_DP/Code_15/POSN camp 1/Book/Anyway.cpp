/*
    TASK:Anyway
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010],b[1010][1010];
int main()
{
    int x,y,k,i,j;
    scanf("%d %d %d",&x,&y,&k);
    while(k--){
        scanf("%d %d",&i,&j);
        b[i+1][j+1]=1;
    }
    dp[1][1]=1;
    for(i=1;i<=x+1;i++){
        for(j=1;j<=y+1;j++){
            if(b[i][j]==1)
                dp[i][j]=0;
            else
                dp[i][j]+=(dp[i-1][j]+dp[i][j-1])%1000000;
            //printf("%d ",dp[i][j]);
        }
        //printf("\n");
    }
    printf("%d\n",dp[x+1][y+1]%1000000);
    return 0;
}
