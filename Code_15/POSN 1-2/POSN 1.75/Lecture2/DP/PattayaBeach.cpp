/*
    TASK:PattayaBeach
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[3100],b[3100],dp[3100][3100];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
    scanf("%d",&b[i]);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    printf("%d\n",dp[n][n]);
}
