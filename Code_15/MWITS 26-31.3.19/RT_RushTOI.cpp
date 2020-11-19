/*
    TASK:RT_RushTOI
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[310][310];
int main(){
    int n,m,i,j,u,v,w,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            a[i][j]=1<<20;
        }
    }
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        a[u][v]=min(a[u][v],w);
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(a[i][j]==1<<20)printf("0 ");
            else printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
/*
4 5
1 2 10
2 3 10
1 3 15
4 4 10
4 1 10
*/
