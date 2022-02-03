/*
    TASK:AP Group
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    int s,k;
    bool operator < (const A & o) const{
        if(s!=o.s) return s>o.s;
        return k<o.k; 
    }
};
A a[100010];
int dp[100010];
int main()
{
    int q,n,cnt,idx;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i].s,&a[i].k);
        }
        sort(a+1,a+1+n);
        memset(dp,0,sizeof dp);
        cnt=0;
        for(int i=1;i<=n;i++){
            idx=upper_bound(dp,dp+cnt,a[i].k)-dp;
            if(idx==cnt) cnt++;
            dp[idx]=a[i].k;
        }
        printf("%d\n",cnt);
    }
    return 0;
}