/*
    TASK:Swift Mirror
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    int i,j,di,w;//1=u 2=r 3=d 4=l
};
int mark[4][501][501],di[]= {1,-1,0,0},dj[]= {0,0,-1,1};
char a[501][501];
int ans[501*501*4][4];
queue< A >q;
int n,m;
void bfs(int si,int sj,int d)
{
    while(!q.empty())   q.pop();
    memset(mark,0,sizeof mark);
    mark[d][si][sj]=1;
    q.push({si,sj,d,1});
    while(!q.empty())
    {
        int ni=q.front().i,nj=q.front().j,ndi=q.front().di,nw=q.front().w;q.pop();
        ans[nw][d]=1;
        int nxi=ni+di[ndi],nxj=nj+dj[ndi],nxdi=ndi;
        if(!nxi||!nxj||nxi>n||nxj>m||a[nxi][nxj]=='S')  continue;
        if(a[nxi][nxj]=='\\')   nxdi=3-nxdi;
        if(a[nxi][nxj]=='/')    nxdi=(nxdi+2)%4;
        if(mark[nxdi][nxi][nxj])    {ans[1000005][d]=1;continue;}
        mark[nxdi][nxi][nxj]=1;
        q.push({nxi,nxj,nxdi,nw+1});
    }
}
int main()
{
    int si,sj,i,j;
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            scanf(" %c",&a[i][j]);
        }
    }
    scanf("%d %d",&si,&sj);
    for(i=0; i<4; i++)  bfs(si,sj,i);
    if(ans[1000005][1]) {printf("U\nInfinity\n");return 0;}
    if(ans[1000005][3]) {printf("R\nInfinity\n");return 0;}
    if(ans[1000005][0]) {printf("D\nInfinity\n");return 0;}
    if(ans[1000005][2]) {printf("L\nInfinity\n");return 0;}
    for(int i=1000000;i;i--)
    {
        if(ans[i][1]) {printf("U\n%d\n",i);return 0;}
        if(ans[i][3]) {printf("R\n%d\n",i);return 0;}
        if(ans[i][0]) {printf("D\n%d\n",i);return 0;}
        if(ans[i][2]) {printf("L\n%d\n",i);return 0;}
    }
}
/*
5 5
..../
../..
.....
.....
..\./
2 5
*/
