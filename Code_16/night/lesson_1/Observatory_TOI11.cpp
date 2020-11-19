/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[2020][2020],ri[2020][2020],sri[2020][2020],sle[2020][2020],le[2020][2020],qs[2020][2020];
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            ri[i][j]=a[i][j]+ri[i-1][j-1];
            sri[i][j]=ri[i][j]+sri[i][j-1];
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            le[i][j]=a[i][j]+le[i-1][j+1];
            sle[i][j]=sle[i][j+1]+le[i][j];
        }
    }
    // printf("\n");
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%d ",le[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%d ",sle[i][j]);
    //     }
    //     printf("\n");
    // }
    int ma=-2e9,now;
    for(int i=k;i<=n;i++){
        for(int j=k;j<=m;j++){
            now=sri[i][j]-sri[i-k][j-k];
            now-=(qs[i][j-k]-qs[i-k][j-k]);
            ma=max(ma,now);
            // printf("%d %d %d\n",i,j,now);
        }
    }
    // printf("%d\n",ma);
    for(int i=k;i<=n;i++){
        for(int j=m-k+1;j>=1;j--){
            now=sle[i][j]-sle[i-k][j+k];
            now-=(qs[i][m]-qs[i][j+k-1]-qs[i-k][m]+qs[i-k][j+k-1]);
            // printf("%d %d %d\n",i,j,now);
            ma=max(ma,now);
        }
    }
    printf("%d\n",ma);
    return 0;
}
