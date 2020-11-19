/*
    TASK:Ents Tribe
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[10000010];
int main(){
    int k,p,i;
    scanf("%d %d",&k,&p);
    dp[2]=1;
    for(i=3;i<=k;i++){
        dp[i]+=dp[i-1];
        if(i%2==0)dp[i]+=dp[i/2];
        dp[i]%=p;
    }
    printf("%d\n",dp[k]);
    return 0;
}
