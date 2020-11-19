/*
    TASK: Dog Village
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
   int i,j;
};
queue< A > q;
int a[1050][1050],zi[1050],zj[1050];
int dis[1050][1050],di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
int main()
{
    int n,m,i,j,k=0,l,d,v,nexti,nextj,cou=0;
    memset(dis,-1,sizeof dis);
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
            {
                dis[i][j]=0;
                q.push({i,j});
            }
        }
    }
    while(!q.empty())
    {
        i=q.front() .i,j=q.front() .j;
        q.pop();
        for(v=0;v<4;v++)
        {
            nexti=i+di[v],nextj=j+dj[v];
            if(nexti<0 || nextj<0 || nexti>=n || nextj>=m)continue;
            if(dis[i][j]+1>=a[nexti][nextj])continue;
            if(dis[nexti][nextj]!=-1)continue;
            dis[nexti][nextj]=dis[i][j]+1;
            q.push({nexti,nextj});
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            //printf("%d ",dis[i][j]);
            if(dis[i][j]==-1)cou++;
        }
        //printf("\n");
    }

    printf("%d",cou);
    return 0;
}
/*
4 4
0 1 3 2
4 3 1 1
2 0 1 1
0 4 1 9
*/
