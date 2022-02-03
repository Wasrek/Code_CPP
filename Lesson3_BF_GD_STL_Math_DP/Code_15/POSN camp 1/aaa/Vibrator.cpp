/*
    TASK:Vibrator
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[50010]={1};
int main()
{
    int n,c,num,i;
    scanf("%d %d",&c,&n);
    while(n--){
        scanf("%d",&num);
        for(i=c;i>=num;i--)
            if(dp[i-num])
            dp[i]=1;
    }
    for(i=c;i>=1;i--){
        if(dp[i]==1){
        printf("%d\n",i);
        return 0;
        }
    }
    return 0;
}
