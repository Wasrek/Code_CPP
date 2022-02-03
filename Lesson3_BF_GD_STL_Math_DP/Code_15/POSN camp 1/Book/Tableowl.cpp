/*
    TASK:Tableowl
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[600][600];
int main()
{
    int i,j,r,c,ans=10000000;
    scanf("%d %d",&r,&c);
    for(i=0;i<=r+1;i++)
        for(j=0;j<=c+1;j++)
        a[i][j]=1000000000;
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
        scanf("%d",&a[i][j]);
    for(i=r-1;i>=1;i--)
        for(j=1;j<=c;j++)
        a[i][j]+=min(a[i+1][j-1],min(a[i+1][j],a[i+1][j+1]));
    for(j=1;j<=c;j++)
        if(a[1][j]<ans)
            ans=a[1][j];
    printf("%d\n",ans);
    return 0;

}
