//BreakTheSticks
#include<bits/stdc++.h>
using namespace std;
int mic[55][55];
int val[55];
int dp(int st,int en)
{
    if(st+1==en)
        return 0;
    if(mic[st][en])
        return mic[st][en];
    int mi=INT_MAX;
    for(int i=st+1;i<en;i++)
        mi=min(mi,dp(st,i)+dp(i,en));
    return mic[st][en]=mi+val[en]-val[st];
}
int main()
{
    int n,k,i;
    scanf("%d %d",&n,&k);
    for(i=1;i<=k;i++)
        scanf("%d",&val[i]);
    val[k+1]=n;
    printf("%d",dp(0,k+1));
    return 0;
}
