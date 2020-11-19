/*
    TASK:TOI8_maze
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,t;
};
int a[170][170],dis[2][170][170],di[]={1,-1,0,0},dj[]={0,0,1,-1};
queue< A > q;
int main()
{
    int n,m,si,sj,ei,ej;
    scanf("%d %d %d %d %d %d",&n,&m,&si,&sj,&ei,&ej);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            dis[1][i][j]=dis[0][i][j]=2e9;
        }
    }
    int ni,nj,nt,ii,jj;
    dis[0][si][sj]=0;
    q.push({si,sj,1});
    while(!q.empty()){
        ni=q.front().i;
        nj=q.front().j;
        nt=q.front().t;
        q.pop();
        for(int i=0;i<4;i++){
            ii=ni+di[i];
            jj=nj+dj[i];
            if(ii<1 || ii>n || jj<1 || jj>m) continue;
            if(dis[0][ii][jj]<=nt+1) continue;
            dis[0][ii][jj]=nt+1;
            if(!a[ii][jj]) continue;
            q.push({ii,jj,nt+1});
        }
    }
    while(!q.empty())q.pop();

    dis[1][ei][ej]=0;
    q.push({ei,ej,1});
    while(!q.empty()){
        ni=q.front().i;
        nj=q.front().j;
        nt=q.front().t;
        q.pop();
        for(int i=0;i<4;i++){
            ii=ni+di[i];
            jj=nj+dj[i];
            if(ii<1 || ii>n || jj<1 || jj>m) continue;
            if(dis[1][ii][jj]<=nt+1) continue;
            dis[1][ii][jj]=nt+1;
            if(!a[ii][jj]) continue;
            q.push({ii,jj,nt+1});
        }
    }

    int cnt=0,mi=2e9;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j] || dis[0][i][j]==2e9 || dis[1][i][j]==2e9) continue;
            cnt++;
            mi=min(mi,dis[0][i][j]+dis[1][i][j]-1);
        }
    }
    printf("%d\n%d\n",cnt,mi);
    return 0;
}