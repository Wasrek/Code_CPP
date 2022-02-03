/*
    TASK:FC_Domine
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],r[1010][1010],c[1010][1010];
int main()
{
    int n,k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            scanf("%d",&a[i][j]);
            r[i][j]=r[i-1][j]+a[i][j];
            c[i][j]=c[i][j-1]+a[i][j];
        }
    }
    return 0;
}