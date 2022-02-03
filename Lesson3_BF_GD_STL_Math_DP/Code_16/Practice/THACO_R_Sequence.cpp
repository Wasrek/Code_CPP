/*
    TASK:R_Sequence
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[500010],h[500010],near[500010],s[500010],dp[500010];
int main()
{
    int n,now;  
    scanf("%d",&n);
    memset(h,0,sizeof h);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        near[i]=h[a[i]];
        h[a[i]]=i;
    }
    // for(int i=1;i<=n;i++){
    //     printf("%d ",near[i]);
    // }
    // printf("\n");
    for(int i=1;i<=n;i++){
        if(near[i]<=0) continue;
        now=i-1;
        while(a[i]!=a[now] && now>0){
            if(s[now]>0) now=s[now]-1;
            else{
                now=-1;
                break;
            }
        }
        if(now<=0) s[i]=0;
        else s[i]=now;
    }
    // for(int i=1;i<=n;i++){
    //     printf("%d ",s[i]);
    // }
    // printf("\n");
    long long sum=0ll;
    for(int i=1;i<=n;i++){
        if(s[i]>0) dp[i]=dp[s[i]-1]+1;
        sum+=dp[i];
    }
    printf("%lld\n",sum);
    return 0;
}