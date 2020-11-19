/*
    TASK:48_Follow
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    int u,v,w;
    bool operator <(const A&o)const
    {
        return w>o.w;
    }
};
priority_queue< A > h;
vector<int> g[1010];
int mark[10100][2],pea[1010],dis[1010][1010],di[1010],na[1010][1010];
int main()
{
    int q,n,m,s,e,t,p,u,v,w,i,j,last,tu,tv,tw;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d ",&n,&m);
        scanf("%d %d %d %d",&s,&e,&t,&p);
        for(i=0; i<p; i++)
            scanf("%d",&pea[i]);

        for(i=0; i<=n; i++)
            di[i]=1<<30,dis[i][i]=0;
        for(i=1; i<=m; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
                g[u].push_back(v);
                g[v].push_back(u);
                dis[u][v]=dis[v][u]=w;
                na[u][v]=na[v][u]=i;
        }
        last=0;
        for(i=1; i<p; i++)
        {
            mark[na[pea[i-1]][pea[i]]][1]=mark[na[pea[i]][pea[i-1]]][1]=last;
            mark[na[pea[i-1]][pea[i]]][2]=mark[na[pea[i]][pea[i-1]]][2]=last+dis[pea[i]][pea[i-1]];
            last=last+dis[pea[i]][pea[i-1]];
        }
//        for(i=1;i<=m;i++){
//            printf(" mark %d %d %d\n",i,mark[i][1],mark[i][2]);
//        }
        h.push({s,s,t});
        di[s]=t;
        while(!h.empty())
        {
            tu=h.top().u,tv=h.top().v;
            tw=h.top().w;
            h.pop();
//            printf("--%d %d %d %d\n",tu,tv,tw,tw-t+1);
            if(tv==e)
            {
                printf("%d\n",tw-t);
                break;
            }
            for(auto x:g[tv])
            {
                if(di[tv]+dis[tv][x]>di[x])
                    continue;
                if(di[tv]>=mark[na[tv][x]][1] && di[tv]<=mark[na[tv][x]][2])
                {
                    if(mark[na[tv][x]][2]+dis[tv][x]<di[x]){
                        di[x]=mark[na[tv][x]][2]+dis[tv][x];
                        h.push({tv,x,di[x]});
                    }
//                    printf("--------%d %d %d %d %d\n",tv,x,mark[na[tv][x]][2],dis[tv][x],di[x]);
                }
                else if(di[tv]+dis[tv][x]<di[x])
                {
                    di[x]=di[tv]+dis[tv][x];
                    h.push({tv,x,di[x]});
                }
            }
        }
        while(!h.empty())
            h.pop();
        for(i=1; i<=n; i++)
            g[i].clear();
        memset(pea,0,sizeof pea);
        memset(mark,0,sizeof mark);
        memset(di,0,sizeof di);
        memset(na,0,sizeof na);
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
8 9
1 5 5 5
1 2 3 4 5
1 2 8
2 3 10
2 7 4
3 4 23
3 6 5
4 8 4
4 5 5
6 8 3
6 7 40
*/
