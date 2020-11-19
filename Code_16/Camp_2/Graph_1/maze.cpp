/*
    TASK:maze
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,t;
};
int dis[2][200][200],di[]={1,-1,0,0},dj[]={0,0,1,-1},a[200][200];
queue< A > q;
int main()
{
    int n,m,si,sj,ei,ej;
    scanf("%d %d",&n,&m);
    scanf("%d %d",&si,&sj);
    scanf("%d %d",&ei,&ej);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dis[0][i][j]=dis[1][i][j]=2e9;
        }
    }
    q.push({si,sj,1});
    dis[0][si][sj]=0;
    int ti,tj,bi,bj,t,ii,jj;
    while(!q.empty()){
        ti=q.front().i;
        tj=q.front().j;
        t=q.front().t;
        q.pop();
        for(int k=0;k<4;k++){
            ii=ti+di[k];
            jj=tj+dj[k];
            if(ii<1 || ii>n || jj<1 || jj>m) continue;
            if(dis[0][ii][jj]<=t+1) continue;
            dis[0][ii][jj]=t+1;
            if(a[ii][jj]){
                q.push({ii,jj,t+1});
            }
        }
    }
    dis[1][ei][ej]=0;
    while(!q.empty()) q.pop();
    q.push({ei,ej,1});
    while(!q.empty()){
        ti=q.front().i;
        tj=q.front().j;
        t=q.front().t;
        q.pop();
        for(int k=0;k<4;k++){
            ii=ti+di[k];
            jj=tj+dj[k];
            if(ii<1 || ii>n || jj<1 || jj>m) continue;
            if(dis[1][ii][jj]<=t+1) continue;
            dis[1][ii][jj]=t+1;
            if(a[ii][jj]){
                q.push({ii,jj,t+1});
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%d ",dis[0][i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%d ",dis[1][i][j]);
    //     }
    //     printf("\n");
    // }
    int cnt=0,mi=2e9;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j])continue;
            if(dis[0][i][j]==2e9 || dis[1][i][j]==2e9) continue;
            cnt++;
            mi=min(mi,dis[0][i][j]+dis[1][i][j]-1);
        }
    }
    printf("%d\n%d\n",cnt,mi);
    return 0;
}