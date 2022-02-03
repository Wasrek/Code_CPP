/*
    TASK:53Motorbike
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    int j,w;
    bool operator < (const A & o) const
    {
        if(w != o.w)
        {
            return w>o.w;
        }
        else
        {
            return j>o.j;
        }
    }
};
pair<int,int> k[50100];
int ch[50100],c[50100],way[50100];
vector<A> a[50100];
priority_queue<A> h,ans;
int main()
{
    int m,d,t,p,i;
    scanf("%d %d %d %d",&m,&d,&t,&p);
    for(i=1; i<=d; i++)
    {
        scanf("%d %d",&k[i].first,&k[i].second);
        ch[k[i].first]=1;
    }
    int x,y,z,j,l;
    for(i=1; i<=t; i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        a[x].push_back({y,z});
        a[y].push_back({x,z});
    }
    int nw,ww,cd=0;
    h.push({p,0});
    while(!h.empty())
    {
        j=h.top().j;
        nw=h.top().w;
        h.pop();
        if(c[j]==1)
            continue;
        c[j]=1;
        if(ch[j]==1)
        {
            way[j]=nw;
            ch[j]=0;
        }
        for(l=0; l<a[j].size(); l++)
        {
            ww=a[j][l].w;
            h.push({a[j][l].j,ww+nw});
        }
    }
    //printf("2");
    for(i=1; i<=d; i++)
    {
        ans.push({i,way[k[i].first]/k[i].second});
    }
    while(!ans.empty())
        printf("%d ",ans.top().j),ans.pop();
    return 0;
}
/*
3 2 2 1
2 10
3 10
1 2 20
3 1 19
*/
