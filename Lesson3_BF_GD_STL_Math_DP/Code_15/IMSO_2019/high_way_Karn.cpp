#include<bits/stdc++.h>
using namespace std;
vector<int> g[100100],gt[100100];
int dist[100100];
int mark[100100];
int dist2[200000];
int tim[100100];
int qu[200100];
int tqu[200100];
priority_queue<pair<int,int> > qq;
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    for(int i = 0; i < m; i++)
    {
        int st,la;
        scanf("%d %d",&st,&la);
        g[st].push_back(la);
        gt[la].push_back(st);
    }
    int cnt=1;
    int quu=0;
    for(int i = 0; i < q; i++)
    {
        int op,ind;
        scanf("%d %d",&op,&ind);
        if(op==1)
        {
            tim[ind]=cnt++;
        }
        else
        {
            tqu[quu]=cnt-1;
            qu[quu]=ind;
            quu++;
        }
    }
    if(!tim[1])
        qq.push({1e8,1});
    else
        qq.push({tim[1],1});
    while(!qq.empty())
    {
        int now = qq.top().second;
        int noww= qq.top().first;
        qq.pop();
        if(dist[now])
            continue;
        dist[now]=noww;
        for(int i = 0; i < g[now].size(); i++)
        {
            if(dist[g[now][i]]||mark[g[now][i]])
                continue;
            if(tim[g[now][i]])
            {
                qq.push({min(noww,tim[g[now][i]]),g[now][i]});
            }
            else
            {
                qq.push({noww,g[now][i]});
            }
            mark[g[now][i]]++;
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d %d\n",i,dist[i]);
    }
    qq.push({dist[n],n});
    memset(mark,0,sizeof mark);
    while(!qq.empty())
    {
        int now=qq.top().second;
        int noww=qq.top().first;
        qq.pop();
        if(dist2[now])
            continue;
        dist2[now]=noww;
        for(int i = 0; i < gt[now].size(); i++)
        {
            if(dist2[gt[now][i]]||mark[gt[now][i]])
                continue;
            qq.push({min(dist[gt[now][i]],noww),gt[now][i]});
            mark[gt[now][i]]=1;
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d %d %d\n",i,dist[i],tqu[i]);
    }
    for(int i = 0; i < quu; i++)
    {
        if(dist2[qu[i]]>tqu[i])
            printf("1\n");
        else
        {
            printf("0\n");
        }

    }
    return 0;
}
