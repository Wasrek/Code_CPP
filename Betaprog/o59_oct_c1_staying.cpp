/*
    TASK:Staying Salesman
    LANG: CPP
    AUTHOR: WasreK
    ALGO: DP
    TYPE: BATCH
    SCORE: 
*/
#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
long long dp[1010][10][4],qs[1010][10][4];
int main()
{
    int n,ka,kb,kc;
    scanf("%d %d %d %d",&n,&ka,&kb,&kc);
    for(int i=1;i<=ka;i++) dp[i][1][0]=1;
    for(int i=1;i<=n;i++){
        for(int k=1;k<(1<<3);k++){
            for(int la=1;la<(1<<3);la++){
                if((la|k)!=k) continue;
                if((1<<0)&k && (k-(k&la)==0 || k-(k&la)==1)){
                    dp[i][k][0]+=(qs[i-1][la][2]-qs[max(0,i-ka-1)][la][2]);
                }
                if((1<<1)&k && (k-(k&la)==0 || k-(k&la)==2)){
                    dp[i][k][1]+=(qs[i-1][la][0]-qs[max(0,i-kb-1)][la][0]);
                }
                if((1<<2)&k && (k-(k&la)==0 || k-(k&la)==4)){
                    dp[i][k][2]+=(qs[i-1][la][0]-qs[max(0,i-kc-1)][la][0]);
                    dp[i][k][2]+=(qs[i-1][la][1]-qs[max(0,i-kc-1)][la][1]);
                }
                dp[i][k][0]+=MOD;dp[i][k][0]%=MOD;
                dp[i][k][1]+=MOD;dp[i][k][1]%=MOD;
                dp[i][k][2]+=MOD;dp[i][k][2]%=MOD;
            }
            for(int la=0;la<3;la++) qs[i][k][la]=qs[i-1][k][la]+dp[i][k][la];
            qs[i][k][0]%=MOD;
            qs[i][k][1]%=MOD;
            qs[i][k][2]%=MOD;
        }
    }
    printf("%lld\n",(dp[n][7][0]+dp[n][7][1]+dp[n][7][2])%MOD);
    return 0;
}