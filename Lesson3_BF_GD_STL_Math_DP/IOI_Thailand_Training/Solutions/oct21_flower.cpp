/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[110][110][110];
int main()
{
    int m,k,a,b,t,cnt1,cnt2;
    cnt1=cnt2=0;
    scanf("%d %d",&m,&k);
    for(int i=1;i<=k;i++){
        scanf("%d %d %d",&a,&b,&t);
        if(t==0) cnt1++;
        else cnt2++;
        for(int j=m-a;j>=0;j--){
            for(int sh=cnt1;sh>=0;sh--){
                for(int lg=cnt2;lg>=0;lg--){
                    if(t==0){
                        if(sh==cnt1) continue;
                        dp[j+a][sh+1][lg]=max(dp[j][sh][lg]+b,dp[j+a][sh+1][lg]);
                    }else{
                        if(lg==cnt2) continue;
                        dp[j+a][sh][lg+1]=max(dp[j][sh][lg]+b,dp[j+a][sh][lg+1]);
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0; i<=cnt1; i++) {
        for(int j=0; j<=cnt2; j++) {
            int mx=max({0, i - 1, j - 1})/2;
            int mn=min(i, j);
            if(mx > mn)
                continue;
            ans = max(ans, dp[m][i][j]);
        }
    }
    // int ans=0;
    // for(int M=0;M<=m;M++){
    //     for(int i=0;i<=cnt1;i++){
    //         for(int j=max((i-1)/2,0);j<=min(cnt2,(i+1)*2);j++){
    //             ans=max(dp[M][i][j],ans);
    //         }
    //     }
    //     // for(int i=0;i<=cnt1;i++){
    //     //     for(int j=0;j<=cnt2;j++){
    //     //         // if(min(i,j)*2+2>max(i,j)) continue;
    //     //         if(max({0,i-1,j-1})/2>min({i,j})) continue;
    //     //         ans=max(ans,dp[M][i][j]);
    //     //     }
    //     // }
    // }
    printf("%d\n",ans);
    return 0;
}