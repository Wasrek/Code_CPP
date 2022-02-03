/*
    TASK:61_Nugget
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000100],nugget[10];
int main()
{
    int q,n,m,i,counter=0,ans,j;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d",&nugget[i]);
        counter++;
        dp[0]=counter;
        for(i=1,ans=0;i<=m;i++){
            for(j=0;j<n;j++){
                if(i-nugget[j]>=0 && dp[i-nugget[j]]==counter){
                    dp[i]=counter;ans++;break;
                }
            }
        }
        printf("%d\n",ans);
    }
}
