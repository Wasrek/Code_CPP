/*
    TASK:maze TOI8
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    int i,j,w;
};
queue< A > bfs;
int a[160][160],di[4]= {1,-1,0,0},dj[4]= {0,0,1,-1};
int dis[2][160][160],x[2],y[2],mark[2][160][160];
int main()
{
    int r,c,i,j,ni,nj,nw,k,ii,jj,cnt=0,Mi=1<<20;
    scanf("%d %d %d %d %d %d",&r,&c,&x[0],&y[0],&x[1],&y[1]);
    for(i=1; i<=r; i++)
    {
        for(j=1; j<=c; j++)
        {
            scanf("%d",&a[i][j]),dis[0][i][j]=dis[1][i][j]=1<<20;
        }
    }
    for(i=0; i<=1; i++)
    {
        bfs.push({x[i],y[i],0});
        while(!bfs.empty())
        {
            ni=bfs.front().i,nj=bfs.front().j,nw=bfs.front().w;
            bfs.pop();
            if(dis[i][ni][nj]!=1<<20) continue;
            dis[i][ni][nj]=nw;
            for(k=0; k<4; k++)
            {
                ii=ni+di[k],jj=nj+dj[k];
                if(ii<1 || jj<1 || ii>r || jj>c)
                    continue;
                if(dis[i][ii][jj]!=1<<20)
                    continue;
                if(a[ii][jj]==1)
                    bfs.push({ii,jj,nw+1});
                if(a[ii][jj]==0)
                    dis[i][ii][jj]=nw+1;
            }
        }
        while(!bfs.empty())bfs.pop();
    }
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            if(a[i][j]==0 && dis[0][i][j]!=1<<20 && dis[1][i][j]!=1<<20){
            cnt++;
            if(dis[0][i][j]+dis[1][i][j]+1<Mi){
                Mi=dis[0][i][j]+dis[1][i][j]+1;
            }
            }
        }
    }
    printf("%d\n%d",cnt,Mi);
    return 0;
}
/*
5 8
4 5
2 8
0 0 1 1 0 0 0 0
1 0 1 1 0 1 1 1
1 0 1 1 1 0 0 1
1 1 0 0 1 0 0 1
0 0 1 1 0 1 1 1
*/
