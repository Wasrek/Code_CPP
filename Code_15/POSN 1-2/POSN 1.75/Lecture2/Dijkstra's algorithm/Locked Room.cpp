/*
    TASK:Locked Room
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    int i,j,w,dm;
    bool operator <(const A&o) const
    {
        return w>o.w;
    }
};
priority_queue<A> h;
int mark[2][60][60],a[60][60],di[]= {0,0,1,-1},dj[]= {1,-1,0,0};
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int si,sj,ei,ej;
    scanf("%d %d %d %d",&si,&sj,&ei,&ej);
    si--;
    sj--;
    ei--;
    ej--;
    h.push({si,sj,0,0});
    int ni,nj,nw,w,nd,d,k;
    while(!h.empty())
    {
        i=h.top().i;
        j=h.top().j;
        w=h.top().w,d=h.top().dm;
        h.pop();
        if(mark[d][i][j])
            continue;
        if(i==ei && j==ej && d==1)
        {
            printf("%d\n",w);
            return 0;
        }
        mark[d][i][j]=1;
        for(k=0; k<4; k++)
        {
            ni=i+di[k];
            nj=j+dj[k];
            if(ni<0 || ni>=n || nj<0 ||nj>=n)
                continue;
            if(a[ni][nj]<0)
            {
                nd=d^1;
            }
            else
            {
                nd=d;
            }
            h.push({ni,nj,w+abs(a[ni][nj]),nd});
        }
    }
    return 0;
}
