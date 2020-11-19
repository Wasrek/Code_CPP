/*
    TASK:Q_game2
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[220][220],ma[220][220],mi[220][220];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            mi[i][j]=2e9;
            ma[i][j]=-2e9;
        }
    }
    ma[1][1]=mi[1][1]=a[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ma[i][j]=max(ma[i][j],max(ma[i-1][j],ma[i][j-1])+a[i][j]);
            mi[i][j]=min(mi[i][j],min(mi[i-1][j],mi[i][j-1])+a[i][j]);
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%d ",mi[i][j]);
    //     }
    //     printf("\n");
    // }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%d ",ma[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d\n",ma[n][m]-mi[n][m]);
    return 0;
}