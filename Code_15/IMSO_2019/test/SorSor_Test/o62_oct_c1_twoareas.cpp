/*
    TASK:twoarea
*/
#include<bits/stdc++.h>
using namespace std;
int a[330][330],qs[330][330];
int main()
{   int m,n;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]>=0){
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+a[i][j];
            }else qs[i][j]=0;
        }
    }
    printf("%d 5\n",n,m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",qs[i][j]);
        }
        printf("\n");
    }
//    for(int i=1;i<=m;i++){
//        for(int j=1;j<=n;j++){
//            if(qs[i])
//        }
//    }
    return 0;
}
