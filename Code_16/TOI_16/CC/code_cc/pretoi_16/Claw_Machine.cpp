/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int a[100010],qs[100010],cnt[100][100010],now[100],dp[100010][100];
int main()
{
    int n,q,l,r,k,ma=0;
    long long ans;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        qs[i]=qs[i-1]+a[i];
        // if(qs[i]<=100){
        //     // printf("%d %d\n",qs[i],i);
        //     cnt[qs[i]][i]++;
        // }
        ma=max(a[i],ma);
    }
    // ma=min(ma,100);
    // if(ma==1){
        int h;
        dp[1][1]=1;
        for(int i=1;i<=n;i++) dp[i][0]=1;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=min(i,100); j++)
            {
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
            }
        }
        while(q--){
            scanf("%d %d %d",&l,&r,&k);
            h=r-l+1;
            if(h<k)printf("0\n");
            else  printf("%d\n",dp[h][k]%mod);
        }
        return 0;
    // }
    // for(int i=2;i<=n;i++){
    //     for(int j=1;j<=ma;j++){
    //         cnt[j][i]+=cnt[j][i-1];
    //         printf("%d %d %d\n",i,j,cnt[j][i]);
    //     }
    // }
    // for(int i=1;i<=n;i++){
    //     for(int j=i;j<=n;j++){
    //         cnt[qs[j]-qs[i-1]][j]++;
    //     }
    // }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=ma;j++){
    //         cnt[j][i]+=cnt[j][i-1];
    //         printf("%d %d %d\n",i,j,cnt[j][i]);
    //     }
    // }
    // // printf("here %d\n",q);
    // // printf("%d\n",q);
    // // return 0;
    // for(int Q=1;Q<=q;Q++){
    //     // printf("%d\n",q);
    //     scanf("%d %d %d",&l,&r,&k);
    //     // printf("hey\n");
    //     ans=0;
    //     for(int i=1;i<=ma;i++){
    //         now[i]=cnt[i][r]-cnt[i][l-1];
    //         printf("%d %d\n",i,now[i]);
    //         if(i>=((k/2)+(k%2))){
    //             ans+=((now[i]*now[k-i])%mod);
    //             ans%=mod;
    //         }
    //     }
    //     // printf("hi\n");
    //     printf("%lld\n",ans);
    // }
    return 0;
}