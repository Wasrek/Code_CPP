/*
    TASK:Q_Spy
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
int p[1010];
priority_queue< A > h;
int fin(int i)
{
    if(p[i]==i)
        return i;
    return p[i]=fin(p[i]);
}
int main()
{
    int n,i,j,now,ans,u,v,w;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d",&now);
            if(j<=i)
                continue;
            h.push({i,j,now});
        }
    }
    for(i=1; i<=n; i++)
    {
        scanf("%d",&now);
        h.push({n+1,i,now});
    }
    for(i=1;i<=n+1;i++)p[i]=i;
    ans=0;
    while(!h.empty()){
        u=h.top().u;
        v=h.top().v;
        w=h.top().w;
        h.pop();
        if(fin(u)==fin(v))continue;
        p[fin(u)]=fin(v);
        ans+=w;
    }
    printf("%d\n",ans);
}
/*
5
0 3 12 15 11
3
0 14 3 20
12 14 0 11 7
15 3 11 0 15
11 20 7 15 0
5 10 10 10 10
*/
