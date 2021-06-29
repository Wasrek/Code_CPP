#include<bits/stdc++.h>
using namespace std;
int a[450],dp[450][450],k;
int play(int l,int r)
{
    if(l==r)         return dp[l][r]=1;
    if(l>r)          return dp[l][r]=0;
    if(dp[l][r]!=-1) return dp[l][r];
    int cnt=1;
    for(int i=l+1;i<=r;i++){
        if(a[i]!=a[i-1]) cnt++;
    }
    int val,minn=cnt;
    for(int i=l;i<r;i++){
        val=play(l,i)+play(i+1,r);
        minn=min(minn,val);
    }
    if(a[l]==a[r]){
        if((a[l]!=a[l+1] && a[r]!=a[r-1]) || l+1==r)
            val=play(l+1,r-1)+1;
        else
            val=play(l+1,r-1);
        minn=min(minn,val);
    }
    return dp[l][r]=minn;
}
int main()
{
    int q,n,maxx=-1e9;
    scanf("%d %d",&q,&k);
    while(q--){
        memset(dp,-1,sizeof dp);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        play(1,n);
        maxx=max(maxx,dp[1][n]);
    }
    printf("%d\n",maxx);
    return 0;
}