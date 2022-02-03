/*
    TASK:Yahoo Rope
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010],l[1010],dp[1010],r[1010];
int main()
{
    int n,q,now,cnt,ub,ma;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        memset(dp,0,sizeof dp);
        cnt=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            a[i]++;
            ub=lower_bound(dp,dp+cnt,a[i])-dp;
            if(ub==cnt)cnt++;
            dp[ub]=a[i];
            l[i]=cnt;
        }
        memset(dp,0,sizeof dp);
        cnt=0;
        for(int i=n;i>=1;i--){
            ub=lower_bound(dp,dp+cnt,a[i])-dp;
            if(ub==cnt)cnt++;
            dp[ub]=a[i];
            r[i]=cnt;
        }
        // for(int i=1;i<=n;i++) printf("%d ",l[i]);
        // printf("\n");
        ma=-2e9;
        for(int i=1;i<n;i++){
            // printf("%d ",r[i]);
            ma=max(ma,l[i]+r[i]-1);
        }
        printf("%d\n",ma);
        // printf("\n");
    }
    return 0;
}