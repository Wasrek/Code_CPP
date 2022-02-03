/*
    TASK:FC_Explore
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[500500],hin[500500];
vector<int> warp[500500];
int main()
{
    int n,m,k,i,r,s,j;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&r,&s);
        warp[r].push_back(s);
    }
    for(i=0;i<k;i++){
        scanf("%d",&r);;
        hin[r]=1;
    }
    dp[1]=1;
    for(i=1;i<=n;i++){
        if(dp[i]==0) continue;
        if(hin[i]==0) dp[i+1]=1;
        for(j=0;j<warp[i].size();j++)
            dp[ warp[i][j] ]=1;
    }
    printf("%d ",dp[n]);
    if(dp[n]==0){
        for(i=n-1;i>=1;i--)
            if(dp[i])
            break;
        printf("%d\n",i);
    }
    return 0;
}
