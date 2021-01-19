/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int s,t,w;
    bool operator<(const A & o) const{
        if(s!=o.s)return s<o.s;
        return t<o.t;
    }
};
A a[1010],dp[1010];
int main()
{
    int n,ma=0,now,cou;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&a[i].s,&a[i].t,&a[i].w);
    }
    sort(a+1,a+n+1);
    a[0].s=0; a[0].t=0;
    dp[0].t=0;
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=0;j--){
            if(a[j].t>a[i].s) continue;
            if(dp[j].w+a[i].w>dp[i].w){
                dp[i].w=dp[j].w+a[i].w;
                dp[i].s=j;
                dp[i].t=dp[j].t+1;
            }
            if(dp[i].w>ma){
                ma=dp[i].w;
                now=i;
                cou=dp[i].t;
            }
        }
    }
    printf("%d\n%d\n",ma,cou);
    while(now>0){
        printf("%d ",now);
        now=dp[now].s;
    }
    return 0;
}