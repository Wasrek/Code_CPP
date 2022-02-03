/*
    TASK:Swift Banner
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[305][305],dp[305][305];
int mac(int s,int t){
    if(dp[s][t]!=-1) return dp[s][t];
    if(s==t)return a[s][t];
    int i;
    dp[s][t]=0;
    for(i=s;i<=t;i++){
        dp[s][t]=max(mac(s,i)+mac(i+1,t),dp[s][t]);
    }
    dp[s][t]+=a[s][t];
    return dp[s][t];
}
int main(){
    int n,m,l,r,ans,i;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&l,&r);
        a[l][r]++;
    }
    memset(dp,-1,sizeof dp);
    ans=mac(1,n);
    printf("%d\n",m-ans);
}
/*
10 6
1 5
4 10
1 3
4 5
4 5
3 7
*/
