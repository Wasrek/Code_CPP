/*
    TASK:PT_Drink Water
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int water[25][25],dp[2000100],n;
int play(int bit){
    if(dp[bit]!=-1) return dp[bit];
    int mi=1e9,i,j;
    int z[20],cntz=0;//z=zero
    int o[20],cnto=0;//o=one
    for(i=0;i<n;i++){
        if((1<<i)&bit) o[++cnto]=i;
        else z[++cntz]=i;
    }
    for(i=1;i<=cnto;i++){
        for(j=1;j<=cntz;j++){
            mi=min(mi,water[z[j]][o[i]]+play(bit|(1<<z[j])));
        }
    }
    return dp[bit]=mi;
}
int main(){
    int q,k,i,j,ans,cnt;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        memset(dp,-1,sizeof dp);
        dp[(1<<n)-1]=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&water[i][j]);
            }
        }
        ans=1e9;
        for(i=1;i<(1<<n);i++){
            for(j=0,cnt=0;j<n;j++){
                if(i&(1<<j)) cnt++;
            }
            if(cnt==k) {ans=min(ans,play(i));}
        }
        printf("%d\n",ans);
    }
}
