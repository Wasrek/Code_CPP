/*
    TASK:RC_Rapid Code
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dis[330][330];
int main(){
    int n,m,s,e,w,i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            dis[i][j]=1<<20;
        }
    }
    for(i=1;i<=n;i++)dis[i][i]=0;
    while(m--){
        scanf("%d %d %d",&s,&e,&w);
        dis[s][e]=min(dis[s][e],w);
    }
//    for(i=1;i<=n;i++){
//        for(j=1;j<=n;j++){
//
//            printf("%d ",dis[i][j]);
//        }
//        printf("\n");
//    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(dis[i][j]==1<<20)printf("-1 ");
            else printf("%d ",dis[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
4 5
1 2 10
2 3 10
1 3 15
4 4 10
4 1 10
*/
