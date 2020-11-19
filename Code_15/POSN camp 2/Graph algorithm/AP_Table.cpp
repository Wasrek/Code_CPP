/*
    TASK:AP_Table
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    int i,j,w;
    char a;
    bool operator <(const A&o) const
    {
        return w>o.w;
    }
};
char s[50][50];
int dis[40][40][40][40],di[4]= {1,-1,0,0},dj[4]= {0,0,1,-1};
priority_queue< A > dijk;
int main()
{
    int q,n,x,y,i,j,k,l,ii,jj,iii,jjj,w,ans=0;
    char a;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d %d",&n,&x,&y);
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf(" %c",&s[i][j]);
            }
        }
        for(i=0; i<=n; i++)
        {
            for(j=0; j<=n; j++)
            {
                for(k=0; k<=n; k++)
                {
                    for(l=0; l<=n; l++)
                    {
                        dis[i][j][k][l]=1<<30;
                    }
                }
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                dijk.push({i,j,0,s[i][j]});
                dis[i][j][i][j]=0;
                while(!dijk.empty())
                {
                    ii=dijk.top().i,jj=dijk.top().j,w=dijk.top().w;
                    a=dijk.top().a;
                    dijk.pop();
                    for(k=0; k<4; k++)
                    {
                        iii=ii+di[k],jjj=jj+dj[k];
                        if(iii<0 || jjj<0 || iii>=n || jjj>=n)
                            continue;
                        if(a==s[iii][jjj] && dis[i][j][ii][jj]+x<dis[i][j][iii][jjj])
                        {
                            dis[i][j][iii][jjj] = dis[i][j][ii][jj]+x;
                            dijk.push({iii,jjj,dis[i][j][iii][jjj],s[iii][jjj]});
                        }
                        if(a!=s[iii][jjj]&& dis[i][j][ii][jj]+y<dis[i][j][iii][jjj])
                        {
                            dis[i][j][iii][jjj] = dis[i][j][ii][jj]+y;
                            dijk.push({iii,jjj,dis[i][j][iii][jjj],s[iii][jjj]});
                        }
                    }
                }
            }
        }
        for(i=0; i<=n; i++)
        {
            for(j=0; j<=n; j++)
            {
                for(k=0; k<=n; k++)
                {
                    for(l=0; l<=n; l++)
                    {
                        if(dis[i][j][k][l]!=1<<30)
                            ans=max(ans,dis[i][j][k][l]);
                    }
                }
            }
        }
        printf("%d\n",ans);
        ans=0;
    }
}
