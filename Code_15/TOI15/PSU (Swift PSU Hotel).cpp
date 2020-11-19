/*
    TASK:PSU (Swift PSU Hotel)
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],dp[150][100010],qs[100010];
int main(){
    int n,k,p,i,j;
    scanf("%d %d %d",&n,&k,&p);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        qs[i]=qs[i-1]+a[i];
    }
    if(k*p>=n){
        printf("%d\n",qs[n]);
        return 0;
    }
    for(i=1;i<=k;i++){
        for(j=i*p;j<=n;j++){
            dp[i][j]=dp[i-1][j-p]+qs[j]-qs[j-p];
            dp[i][j]=max(dp[i][j],dp[i][j-1]);
        }
    }
    printf("%d\n",dp[k][n]);
    return 0;
}
