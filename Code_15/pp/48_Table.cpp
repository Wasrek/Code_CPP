#include<bits/stdc++.h>
using namespace std;
struct A
{
    int i,j,w,att;
    bool operator < (const A& o) const
    {
        return w>o.w;
    }
};
priority_queue <A> q;
pair<int,int> val[305][5005],ro[305];
int coun[100005];
int main()
{
    int n,m,t,i,j,k,v,op,w,att;
    scanf("%d %d %d",&n,&m,&t);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            q.push({i,j,0,0});
    for(k=1;k<=t;k++)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d %d %d",&i,&j,&v);
            if(val[i][j].second<ro[i].second)
                coun[ro[i].second]--;
            val[i][j]={v,k};
            q.push({i,j,v,k});
        }
        if(op==2)
        {
            scanf("%d %d",&i,&v);
            ro[i]={v,k};
            q.push({i,-1,v,k});
            coun[k]=m;
        }
        if(op==3)
        {
            scanf("%d %d",&i,&j);
            if(val[i][j].second<ro[i].second)
                printf("%d\n",ro[i].first);
            else
                printf("%d\n",val[i][j].first);
        }
        if(op==4)
        {
            while(!q.empty())
            {
                i=q.top().i;
                j=q.top().j;
                w=q.top().w;
                att=q.top().att;
                if(j==-1)
                {
                    if(ro[i].second==att&&coun[ro[i].second])
                    {
                        printf("%d\n",w);
                        break;
                    }
                }
                else
                {
                    if(val[i][j].second==att&&val[i][j].second>=ro[i].second)
                    {
                        printf("%d\n",w);
                        break;
                    }
                }
                q.pop();
            }
        }
    }
    return 0;
}
