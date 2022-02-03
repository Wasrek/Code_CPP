/*
    TASK:Break the sticks
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[55],dp[55][55];
int mcm(int l,int r,int s,int e){
    if(l+1==r || dp[l][r]) return dp[l][r];
    int mi=2e9;
    for(int k=l+1;k<r;k++){
        mi=min(mi,mcm(l,k,s,a[k])+mcm(k,r,a[k],e)+e-s);
    }
    dp[l][r]=mi;
    return mi;
}
int main()
{
    int l,n,ans;
    scanf("%d %d",&l,&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    ans=mcm(0,n+1,0,l);
    printf("%d\n",ans);
    return 0;
}