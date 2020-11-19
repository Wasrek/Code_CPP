/*
    TASK:Logistic TOI14
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    long long u,w;
};
struct B
{
    long long u,w,h,f;
    bool operator<(const B & o)const
    {
        if(w!=o.w)
            return w>o.w;
        return h<o.h;
    }
};
vector< A > g[110];
long long a[110],dis[110][110][2];
priority_queue< B >h;
int main()
{
    long long n,i,s,d,f,m,u,v,w,ha,j,fr,k;
    scanf("%lld",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
        for(j=0; j<=100; j++)
            dis[i][j][1]=dis[i][j][0]=1<<30;
    }
    scanf("%lld %lld %lld",&s,&d,&f);
    dis[s][0][1]=0;
    dis[s][0][0]=0;
    scanf("%lld",&m);
    while(m--)
    {
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    h.push({s,0,0,1});
    while(!h.empty())
    {
        u=h.top().u;
        w=h.top().w;
        ha=h.top().h;
        fr=h.top().f;
        h.pop();
        if(dis[u][ha][fr]<w)
            continue;
        //printf("%lld %lld %lld %lld\n",u,w,ha,fr);
        if(u==d && ha==f)
        {
            //for(i=1;i<=n;i++)printf("%lld\n",dis[i][f]);
            printf("%lld\n",w);
            return 0;
        }
        if(fr && w<dis[u][f][0] && w<dis[u][f][1])
        {
            dis[u][f][0]=w;
            h.push({u,w,f,0});
        }
        for(i=1; i<=f-ha; i++)
        {
            if(w+(a[u]*i)<dis[u][ha+i][fr])
            {
                dis[u][ha+i][fr]=w+(a[u]*i);
                h.push({u,w+(a[u]*i),ha+i,fr});
            }
        }
        for(auto x: g[u])
        {
            if(ha>=x.w && w<dis[x.u][ha-x.w][fr])
            {
                dis[x.u][ha-x.w][fr]=w;
                h.push({x.u,w,ha-x.w,fr});
            }
        }
    }
    //printf("%lld\n",dis[d][f]);
    return 0;
}
/*
4
7 1 8 10
1 4 100
5
1 2 60
1 3 50
1 4 90
2 4 30
3 4 20

5
10 1 3 10 30
1 4 20
4
1 2 1
1 5 5
4 5 20
3 4 2
*/
