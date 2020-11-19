/*
    TASK:BUU Dogs
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[100][100],a[100][100];
int main()
{
    long long r,c,i,j,p;
    scanf("%lld %lld %lld",&c,&r,&p);
    while(p--){
        scanf("%lld %lld",&j,&i);
        a[i][j]=1;//ติ๊กว่ามีหมา อันตราย เป็น 1
    }
    dp[1][0]=1;
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            if(a[i][j]==1)
                dp[i][j]=0;
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    printf("%lld\n",dp[r][c]);
    return 0;
}
