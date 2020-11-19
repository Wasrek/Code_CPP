/*
    TASK:Swift Roof Make
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[5010],b[100010];
long long dp[5010];
int main(){
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[i]=1<<30;
    }
    sort(a+1,a+1+n);
    for(i=1;i<=m;i++){
        scanf("%d",&b[i]);
    }
    for(i=m-1;i>=1;i--){
        if(b[i]>b[i+1])b[i]=b[i+1];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            //printf("%d %d\n",dp[j-1],j);
            dp[i]=min(dp[j-1]+b[a[i]-a[j]+1],dp[i]);
        }
        //printf("%lld\n",dp[i]);
    }
    printf("%lld\n",dp[n]);
    return 0;
}
