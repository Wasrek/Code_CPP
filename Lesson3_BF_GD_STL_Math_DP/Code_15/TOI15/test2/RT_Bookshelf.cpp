/*
    TASK:RT_Bookshelf
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],b[1010][1010];
int main(){
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&b[i][j]);
        }
    }
    printf("-1\n");
    return 0;
}
