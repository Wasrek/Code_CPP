/*
    TASK:Jimmy Bond
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
double a[25][25],dp[22][1<<20];
int main(){
    long long n,i,j,k;
    double ans;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%lf",&a[i][j]);
            a[i][j]/=100.00;
            //printf("%.2f",a[i][j]);
        }
    }
    for(i=0;i<n;i++) dp[0][1<<i]=a[0][i];
    for(i=1;i<n;i++){
        for(j=0;j<(1<<n);j++){
            for(k=0;k<n;k++){
                if(j&(1<<k))dp[i][j]= max(dp[i][j],dp[i-1][j^(1<<k)]*a[i][k]);
            }
        }
    }
    ans=dp[n-1][(1<<n)-1]*100.00;
    printf("%.2f\n",ans);
}
