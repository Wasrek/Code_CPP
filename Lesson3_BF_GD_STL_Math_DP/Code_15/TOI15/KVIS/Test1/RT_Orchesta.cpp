/*
    TASK:RT_Orchesta
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long best(long long n,long long k){
    k++;
    return k*(n/k)*(n/k+1)/2+(n%k)*(n/k+1);
}
long long dp[107][505],cnt[107];
int main(){
    int n,m,k,i,j,num,kk;
    scanf("%d %d %d",&n,&m,&kk);
    for(i=1;i<=n;i++)scanf("%d",&num),cnt[num]++;
    for(i=1;i<=m;i++){
        for(j=0;j<=kk;j++){
            dp[i][j]=1e18;
            for(k=0;k<=j;k++){
                dp[i][j]=min(dp[i][j],best(cnt[i],k)+dp[i-1][j-k]);
            }
        }
    }
    printf("%lld",dp[m][kk]);
    return 0;
}
