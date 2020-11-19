/*
    TASK:RT_Near Cut Game
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,w;
    bool operator<(const A&o)const{
    return w>o.w;
    }
};
int a[100010],cnt[100010];
long long dp[100010];
int main(){
    int q,n,i,j,now;
    long long ans=0;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        j=0;
        ans=0;
        for(i=1;i<=n;i++){
            scanf("%d",&now);
            if(!cnt[now])a[++j]=now;
            cnt[now]++;
        }
        sort(a+1,a+1+j);
        for(i=1;i<=j;i++){
            if(a[i]-a[i-1]>1)dp[i]=dp[i-1]+((long long)cnt[a[i]]*a[i]);
            else dp[i]=max(dp[i-1],dp[i-2]+((long long)cnt[a[i]]*a[i]));
        }
        printf("%lld\n",dp[j]);
        memset(dp,0,sizeof dp);
        memset(cnt,0,sizeof cnt);
    }
}
