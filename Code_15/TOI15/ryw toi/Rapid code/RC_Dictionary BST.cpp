/*
    TASK:RC_Dictionary BST
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[330],qs[330],dp[330][330];
long long play(long long l,long long r)
{
    if(dp[l][r]||l==r)
        return dp[l][r];
    if(l>r)return 0;
    long long Mi=2e9,k,num;
    for(k=l; k<=r; k++)
    {
        num = play(l,k-1)+play(k+1,r)+qs[r]-qs[l-1];
        Mi=min(Mi,num);
    }
    return dp[l][r]=Mi;
}
int main()
{
    long long n,i,k,c,j;
    scanf("%lld",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
        qs[i]=qs[i-1]+a[i];
        dp[i][i]=a[i];
    }
    printf("%lld\n",play(1,n));
//    for(i=1;i<=n;i++){
//        for(j=1;j<=n;j++){
//            printf("%d ",dp[i][j]);
//        }
//        printf("\n");
//    }
}
