/*
    TASK:Magic Card
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[5010],b[5010],dp[5010][5010];
int main(){
    long long n,m,i,j;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(j=1;j<=m;j++){
        scanf("%lld",&b[j]);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j-1]+abs(a[i]-b[j]),max(dp[i-1][j],dp[i][j-1]));
        }
    }
    printf("%lld\n",dp[n][m]);
}
