#include<bits/stdc++.h>
using namespace std;
char a[35][35];
int mark[35][35][35][35],di[]={1,-1,0,0},dj[]={0,0,1,-1},dk[]={-1,1,0,0},dl[]={0,0,-1,1},dis[35][35][35][35];
struct A
{
    int i,j,k,l;
};
queue <A> q;
int main()
{
    int t,i,j,k,l,ni,nj,nk,nl,d,ans,n,m,o;
    scanf("%d",&t);
    while(t--)
    {
        memset(dis,0,sizeof(dis));
        memset(mark,0,sizeof(mark));
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
            scanf(" %s",a[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j]=='#')
                    continue ;
                q.push({0,0,i,j});
                dis[i][j][i][j]=1;
                while(!q.empty())
                {
                    k=q.front().k;
                    l=q.front().l;
                    q.pop();
                    for(o=0;o<4;o++)
                    {
                        nk=k+dk[o];
                        nl=l+dl[o];
                        if(nk<0 || nl<0 || nk>=n || nl>=m)
                            continue ;
                        if(a[nk][nl]=='#')
                            continue ;
                        if(dis[i][j][nk][nl])
                            continue ;
                        dis[i][j][nk][nl]=dis[i][j][k][l]+1;
                        q.push({0,0,nk,nl});
                    }
                }
            }
        }
        ans=INT_MAX;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j]=='A')
                    ni=i,nj=j;
                if(a[i][j]=='B')
                    nk=i,nl=j;
            }
        }
        q.push({ni,nj,nk,nl});
        mark[ni][nj][nk][nl]=1;
        while(!q.empty())
        {
            i=q.front().i;
            j=q.front().j;
            k=q.front().k;
            l=q.front().l;
            q.pop();
            if(ans>dis[i][j][k][l])
            {
                ans=dis[i][j][k][l];
                d=mark[i][j][k][l];
            }
            for(o=0;o<4;o++)
            {
                ni=i+di[o];
                nj=j+dj[o];
                nk=k+dk[o];
                nl=l+dl[o];
                if(ni<0 || nj<0 || ni>=n|| nj>=m || a[ni][nj]=='#')
                    ni=i,nj=j;
                if(nk<0 || nl<0 || nk>=n|| nl>=m || a[nk][nl]=='#')
                    nk=k,nl=l;
                if(mark[ni][nj][nk][nl])
                    continue ;
                mark[ni][nj][nk][nl]=mark[i][j][k][l]+1;
                q.push({ni,nj,nk,nl});
            }
        }
        if(ans==0)
            d=1;
        printf("%d %d\n",ans-1,d-1);
    }
    return 0;
}

