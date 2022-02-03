/*
    TASK:LIS easy
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010],dp[1010],path[1010];
vector<int> ans;
int main()
{
    int n,i,j,Ma=-1,att=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dp[1]=1,path[1]=0;
    for(i=2;i<=n;i++){
        dp[i]=1,path[i]=0;
        for(j=1;j<i;j++){
            if(dp[j]+1>dp[i] && a[j]<a[i])
            dp[i]=dp[j]+1,path[i]=j;
        }
    }
    for(i=1;i<=n;i++)
        if(dp[i]>Ma)
        Ma=dp[i],att=i;
    while(att>0){
        ans.push_back(a[att]);
        att = path[att];
    }
    printf("%d\n",Ma);
    for(i=Ma-1;i>=0;i--)
        printf("%d ",ans[i]);
    return 0;
}
/*
8
-7 10 9 2 3 8 8 1
10
6 3 4 8 10 5 7 1 9 2
*/
