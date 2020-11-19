/*
    TASK:break the sticks
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[60],dp[60][60];
int play(int l,int r,int s,int e)
{
    if(dp[l][r]||l+1==r)
        return dp[l][r];
    int Mi=1<<30,i,num;
    for(i=l+1; i<r; i++)
    {
        num = play(l,i,s,a[i])+play(i,r,a[i],e)+e-s;
        Mi=min(Mi,num);
    }
    return dp[l][r]=Mi;
}
int main()
{
    int l,n,i;
    scanf("%d %d",&l,&n);
    for(i=1; i<=n; i++)
        scanf("%d",&a[i]);
    printf("%d\n",play(0,n+1,0,l));
    return 0;
}
