/*
    TASK:FC_Rearrange
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[10010],dp[10010];
int main(){
    int t,n,k,i,maxx,j;
    scanf("%d",&t);
    while(t--){
        memset(dp,0,sizeof dp);
        scanf("%d %d",&n,&k);
        for(i=1;i<=k;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+1+k);
        dp[0]=1;
        for(i=1;i<k;i++)
        for(j=n-1;j>=0;j--){
            if(dp[j] && j+a[i]<n)
                dp[j+a[i]]=1;
        }
        maxx=0;
        for(i=n-1;i>=0;i--){
        if(dp[i]){
            maxx=i;break;
        }
        }
        printf("%d\n",n-maxx-a[k]);
    }
}
