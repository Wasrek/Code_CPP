/*
    TASK:Ultimate
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int main()
{
    char a;
    int r,c,i,j,Max=0;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            scanf(" %c",&a);
            if(a=='#')
                dp[i][j]=0;
            else
                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            if(dp[i][j]>Max)
                Max=dp[i][j];
        }
    }
    printf("%d\n",Max);
    return 0;
}
