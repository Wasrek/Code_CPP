/*
    TASK:Stair
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[5100];
int main()
{
    int n,k,i,j,l;
    scanf("%d %d",&n,&k);
    dp[0]=1;
    for(i=1;i<=n;i++){
        for(j=5010;j>=i;j--){
            if(dp[j-i]){
                dp[j]+=dp[j-i]%k;
            }
        }
    }
    //for(i=0;i<=n;i++)printf("%d ",dp[i]);
    printf("%d\n",(dp[n]-1)%k);

    return 0;
}
//1 1 1 2 2 3 4 5 6 8 10
