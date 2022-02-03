/*
    TASK:48_Bead
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,e;
};
int a[110];
A ans,dp[110][110];
A play(int l,int r){
    if(l>=r) return dp[l][r];
    if(dp[l][r].e!=-1) return dp[l][r];
    A le,ri,mi;
    mi.e=2e9;
    for(int k=l;k<r;k++){
        le=play(l,k);
        ri=play(k+1,r);
        mi.e=min((le.v*ri.v)+le.e+ri.e,mi.e);
        mi.v=(le.v+ri.v)%100;
    }
    return dp[l][r]=mi;
}
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        memset(dp,-1,sizeof dp);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            dp[i][i].v=a[i];
            dp[i][i].e=0;
        }
        ans=play(1,n);
        printf("%d\n",dp[1][n].e);
    }
    return 0;
}