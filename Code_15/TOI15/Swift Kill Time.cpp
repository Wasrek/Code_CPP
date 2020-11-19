/*
    TASK:Swift Kill Time
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,b,c,w;
};
A r[5100];
int dp[2010][5010];
int main(){
    int n,m,k,s,t,i,j,a,b,c,w,ch=0,ans=-1;
    scanf("%d %d %d",&n,&m,&k);
    scanf("%d %d",&s,&t);
    for(i=1;i<=m;i++){
        scanf("%d %d %d %d",&r[i].a,&r[i].b,&r[i].c,&r[i].w);
    }
    for(i=0;i<=k;i++){
        for(j=1;j<=n;j++){
            dp[i][j]=-1e9;
        }
    }
    dp[0][s]=0;
    for(i=1;i<=k;i++){
        for(j=1;j<=m;j++){
            if(i-r[j].w>=0){
            dp[i][r[j].a] = max(dp[i][r[j].a],dp[i-r[j].w][r[j].b]+r[j].c);
            dp[i][r[j].b] = max(dp[i][r[j].b],dp[i-r[j].w][r[j].a]+r[j].c);
            }
        }
    }
    for(i=1;i<=k;i++){
        if(dp[i][t]>=0)ch=1;
        ans=max(ans,dp[i][t]);
    }
    if(ch)printf("%d\n",ans);
    else printf("Impossible");
    return 0;
}
