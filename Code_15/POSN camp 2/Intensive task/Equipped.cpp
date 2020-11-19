/*
    TASK:Equipped
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[300];
int main(){
    int n,m,p,i,w,k,r;
    scanf("%d %d",&n,&k);
    p=1<<k;
    for(i=1;i<=p;i++)
        dp[i]=1<<30;
    while(n--){
        scanf("%d",&w);
        m=0;
        for(i=0;i<k;i++){
            scanf("%d",&r);
            m*=2;
            if(r==1) m++;
        }
        for(i=0;i<=p;i++){
            dp[i|m]=min(dp[i|m],dp[i]+w);
        }
    }
    printf("%d\n",dp[p-1]);
    return 0;
}
