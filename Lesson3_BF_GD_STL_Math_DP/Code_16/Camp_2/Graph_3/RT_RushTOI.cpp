/*
    TASK:RT_RushTOI
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dis[330][330];
int main()
{
    int n,m,u,v,w;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=1e9;
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        dis[u][v]=min(dis[u][v],w);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis[i][j]>=1e9) printf("0 ");
            else printf("%d ",dis[i][j]);
        }
        printf("\n");
    }
    return 0;
}