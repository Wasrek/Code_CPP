/*
    TASK:RT_Pick Book
    LANG: CPP
    AUTHOR: KersaWCq
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[2100],dp[2100][2100];
int main(){
    int n,j,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        for(j=0;j<=i;j++){
            if(j==0){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j+2]-a[i]);
            }else{
                dp[i][j]=max(dp[i-1][j-1]+a[i],dp[i-1][j+2]-a[i]);
            }
        }
    }
    printf("%d\n",dp[n][0]);
}
