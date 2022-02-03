/*
    TASK:Area Rectangular
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
int main()
{
    int r,c,i,j,k,q,x1,y1,x2,y2;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
    for(j=1;j<=c;j++){
        scanf("%d",&k);
        a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+k;
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        x1++,y1++,x2++,y2++;
        printf("%d\n",a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1]);
    }

    return 0;
}
