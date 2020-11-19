/*
    TASK:FC_Road Cut
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],b[1010][1010],rowa[1010],rowb[1010],cola[1010],colb[1010];
int main()
{
    int r,c,i,j,sum=0,ma=-1;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            scanf("%d",&a[i][j]);
            sum+=a[i][j];
            rowa[i]+=a[i][j];
            cola[j]+=a[i][j];
        }
    }
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            scanf("%d",&b[i][j]);
            rowb[i]+=b[i][j];
            colb[j]+=b[i][j];
        }
    }
    for(i=1;i<=r;i++)
        if(sum-rowa[i]+rowb[i-1]+rowb[i+1]>ma)
        ma=sum-rowa[i]+rowb[i-1]+rowb[i+1];
    for(i=1;i<=c;i++)
        if(sum-cola[i]+colb[i-1]+colb[i+1]>ma)
        ma=sum-cola[i]+colb[i-1]+colb[i+1];
    printf("%d\n",ma);

    return 0;
}
