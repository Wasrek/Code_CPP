/*
    TASK:TT_House
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    int i,j,w;
    bool operator< (const A&o)const
    {
        return w>o.w;
    }
};
int dis[1010][1010],p[1010],cou[1010],mark[1010],mm[1010][1010];
priority_queue< A >h;
int fin(int i)
{
    if(p[i]==i)
        return i;
    else
        return p[i]=fin(p[i]);
}
int main()
{
    int q,n,i,j,ti,tj,tw,man,mi,now;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        for(i=1; i<=n; i++)
            p[i]=i;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                scanf("%d",&dis[i][j]);
                if(i!=j && mm[i][j]==0 && mm[j][i]==0)
                mm[i][j]=1,h.push({i,j,dis[i][j]});
            }
        }
        man=0,now=0;
        while(!h.empty())
        {
            ti=h.top().i;
            tj=h.top().j;
            tw=h.top().w;
            h.pop();
            if(now==n)break;
            if(fin(p[ti])!=fin(p[tj]))
            {
                cou[ti]++;
                cou[tj]++;
                //if(!mark[ti])mark[ti]=1,now++;
                //if(!mark[tj])mark[tj]=1,now++;
                //printf("%d %d %d\n",ti,tj,now);
                p[fin(ti)]=fin(tj);
            }
        }
        while(!h.empty())h.pop();
        for(i=1;i<=n;i++){
            if(cou[i]>man)man=cou[i],mi=i;
            //printf("%d %d \n",mark[i],cou[i]);
        }
        printf("%d %d\n",mi,man);
        memset(cou,0,sizeof cou);
        memset(mark,0,sizeof mark);
        memset(mm,0,sizeof mm);
    }
}
/*
2
4
0 7 12 8
7 0 5 1
12 5 0 6
8 1 6 0
6
0 12 4 5 7 8
12 0 8 7 5 10
4 8 0 1 3 4
5 7 1 0 2 3
7 5 3 2 0 5
8 10 4 3 5 0
*/
