/*
    TASK:Skyline
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000];

int main()
{
    int i,n,l,r,h;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d %d",&l,&h,&r);
        for(i=l;i<r;i++)
            if(dp[i]<h)
            dp[i]=h;
    }
    h=0;
    for(i=1;i<300;i++)
    {
        if(dp[i]!=h){
            printf("%d %d ",i,dp[i]);
            h=dp[i];
        }
    }

    return 0;
}
