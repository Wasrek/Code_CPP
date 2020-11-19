/*
    TASK:OR_Do
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[35][100010],a[100010];
int main(){
    int n,q,i,j,r,s,ans;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        for(j=0;j<30;j++){
            dp[j][i]=dp[j][i-1];
            if(a[i]&(1<<j))
                dp[j][i]++;
        }
    }
    while(q--){
        scanf("%d %d",&r,&s);
        ans=0;
        for(i=0;i<30;i++)
            if(dp[i][s]>dp[i][r-1])
                ans+=(1<<i);
        printf("%d\n",ans);
    }
    return 0;
}
