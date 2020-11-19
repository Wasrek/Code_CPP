/*
    TASK:48_Follow
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct B
{
    int u,v,w;
    bool operator<(const B&o) const
    {
        return w>o.w;
    }
};
priority_queue<B> h;
vector< int > g[1100];
int pa[1100],dis[1100][110],di[1100],mw[1100];
int main()
{
    int q,n,m,s,e,t,p,i,j,x,y,w,tv,tw,k,tu;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&n,&m);
        scanf("%d %d %d %d",&s,&e,&t,&p);
        for(i=1; i<=p; i++)
            scanf("%d",&pa[i]);
        for(i=1; i<=n; i++)
            di[i]=1<<30;
        while(m--)
        {
            scanf("%d %d %d",&x,&y,&w);
            g[x].push_back(y);
            g[y].push_back(x);
            dis[x][y]=dis[y][x]=w;
        }
        for(i=1; i<=p; i++)
            mw[i]=mw[i-1]+dis[pa[i]][pa[i-1]];//printf("%d ",mw[i]);
        for(i=1; i<=p; i++)
            mw[i]-=t;//printf("%d ",mw[i]);
        di[s]=0;
        h.push({s,s,0});
        while(!h.empty())
        {
            tu=h.top().u,tv=h.top().v,tw=h.top().w;
            h.pop();
            k=lower_bound(mw+1,mw+p+1,tw)-mw;
            if(tv==e)
            {
                printf("%d\n",tw);
                break;
            }
            for(i=0; i<g[tv].size(); i++)
            {
                if(pa[k]==tu && pa[k+1]==g[tv][i])
                {
                    if(tv+dis[i][g[tv][i]]+pa[k+1]-tw<di[g[tv][i]])
                    {
                        di[g[tv][i]]=tv+dis[i][g[tv][i]]+pa[k+1]-tw;
                        h.push({tv,g[tv][i],di[g[tv][i]]});
                    }
                    continue;
                }
                if(pa[k]==g[tv][i] && pa[k+1]==tu)
                {
                    if(tv+dis[i][g[tv][i]]+pa[k+1]-tw<di[g[tv][i]])
                    {
                        di[g[tv][i]]=tv+dis[i][g[tv][i]]+pa[k+1]-tw;
                        h.push({tv,g[tv][i],di[g[tv][i]]});
                    }
                    continue;
                }
                if(tv+dis[i][g[tv][i]]<di[g[tv][i]])
                {
                    di[g[tv][i]]=tv+dis[i][g[tv][i]];
                    h.push({tv,g[tv][i],di[g[tv][i]]});
                }
            }
        }
    }
}
/*
2
6 5
1 6 20 4
5 3 2 4
1 2 2
2 3 8
2 4 3
3 5 15
3 6 10
*/
