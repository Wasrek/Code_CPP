/*
    TASK:Q_PatShort
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    long long x,y;
};
vector< A > n;
struct H
{
    long long v,w;
    bool operator<(const H & o) const
    {
        return w>o.w;
    }
};
vector<H> g[310],g2[310];
long long dis[310];
priority_queue< H > h;
long long disf(A a,A b)
{
    long long abx=abs(a.x-b.x),aby=abs(a.y-b.y);
    if(abx>aby || abx==aby){
        return abx;
    }
    else
    {
        if((aby-abx)%2)
            return aby+1;
        else
            return aby;
    }
}
A d1,d2;
H t;
int main()
{
    long long m,q,s,e,di,i,j;
    scanf("%lld %lld",&m,&q);
    for(j=1; j<=m; j++)
    {
        scanf("%lld %lld %lld %lld",&d1.x,&d1.y,&d2.x,&d2.y);
        s=-1,e=-1;
//        printf("-");
        for(i=0; i<n.size(); i++)
        {
            if(n[i].x==d1.x && n[i].y==d1.y && s==-1)
                s=i;
            if(n[i].x==d2.x && n[i].y==d2.y && e==-1)
                e=i;
        }
//        printf("-");
        if(s==-1)
        {
            n.push_back(d1);
            s=n.size()-1;
        }
        if(e==-1)
        {
            n.push_back(d2);
            e=n.size()-1;
        }
        g[s].push_back({e,1});
        g[e].push_back({s,1});
//        printf("-");
    }
//    printf("--");
    for(i=0; i<n.size(); i++)
    {
        for(j=i+1; j<n.size(); j++)
        {
            di=disf(n[i],n[j]);
            g[i].push_back({j,di});
            g[j].push_back({i,di});
        }
    }
    while(q--)
    {
        scanf("%lld %lld %lld %lld",&d1.x,&d1.y,&d2.x,&d2.y);
        for(j=0; j<=300; j++)
            g2[j].clear();
        for(i=0; i<=200; i++)
        {
            for(auto x:g[i])
            {
                g2[i].push_back(x);
            }
        }
        s=-1,e=-1;
        for(i=0; i<n.size(); i++)
        {
            if(n[i].x==d1.x && n[i].y==d1.y && s==-1)
                s=i;
            if(n[i].x==d2.x && n[i].y==d2.y && e==-1)
                e=i;
        }
        if(s==-1)
        {
            s=n.size()+1;
            for(i=0; i<n.size(); i++)
            {
                di=disf(n[i],d1);
                g2[i].push_back({s,di});
                g2[s].push_back({i,di});
            }
        }
        if(e==-1)
        {
            e=n.size()+2;
            for(i=0; i<n.size(); i++)
            {
                di=disf(n[i],d2);
                g2[i].push_back({e,di});
                g2[e].push_back({i,di});
            }
        }
        g2[s].push_back({e,disf(d1,d2)});
        g2[e].push_back({s,disf(d1,d2)});
        for(i=0;i<=300;i++){
            dis[i]=1<<30;
        }
        dis[s]=0;
        h.push({s,0});
//        printf("%lld\n",dis[e]);
        while(!h.empty())
        {
            t=h.top();
            h.pop();
            for(auto x:g2[t.v])
            {
//                cout<<x.w<<endl;
                if(dis[x.v]<=t.w+x.w)
                    continue;
                dis[x.v] = t.w+x.w;
                h.push({x.v,dis[x.v]});
            }
        }
        printf("%lld\n",dis[e]);
    }

    return 0;
}