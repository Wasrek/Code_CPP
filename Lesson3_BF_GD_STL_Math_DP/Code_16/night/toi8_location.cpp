/*
    TASK:TOI8_location
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int qs[1010][1010];
int main()
{
    int n,m,k;
    scanf("%d %d",&n,&m);
    scanf("%d",&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&qs[i][j]);
            qs[i][j]+=(qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]);
        }
    }
    int ma=0,now;
    for(int i=k;i<=n;i++){
        for(int j=k;j<=m;j++){
            now=qs[i][j]-qs[i-k][j]-qs[i][j-k]+qs[i-k][j-k];
            ma=max(now,ma);
        }
    }
    printf("%d",ma);
    return 0;
}