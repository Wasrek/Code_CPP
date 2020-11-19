#include<bits/stdc++.h>
using namespace std;
long long g1[201][201];
long long g2[20][20];
long long ci[20];
long long mark[150000][20],k;
priority_queue < pair< long long,pair<long long,long long> > > q;
void play(long long w,long long val,long long v)
{
    //printf("%lld %lld %lld\n",v,val,w);
    for(long long i=0;i<=k;i++)
        if(mark[val|(1<<i)][i]>-w+g2[v][i])
        {
            mark[val|(1<<i)][i]=-w+g2[v][i];
            q.push(make_pair(w-g2[v][i],make_pair(val|(1<<i),i)));
        }
}
int main()
{
    long long n,m,i,j,l,st,en,w;
    pair< long long,pair<long long,long long> > temp;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(i=1;i<=k;i++)
        scanf("%lld",&ci[i]);
    for(i=0;i<=200;i++)
        for(j=0;j<=200;j++)
            g1[i][j]=1e9;
    while(m--)
    {
        scanf("%lld %lld %lld",&st,&en,&w);
        g1[st][en]=g1[en][st]=min(g1[st][en],w);
    }
    for(l=1;l<=n;l++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                g1[i][j]=min(g1[i][j],g1[i][l]+g1[l][j]);
    ci[0]=1;
    ci[k+1]=n;
    k++;
    for(i=0;i<=k;i++)
        for(j=0;j<150000;j++)
            mark[j][i]=1e9;
    for(i=0;i<=k;i++)
    {
        for(j=0;j<=k;j++)
            g2[i][j]=g1[ci[i]][ci[j]];
    }
    q.push(make_pair(0,make_pair(1,0)));
    mark[1][0]=0;
    while(!q.empty())
    {
        temp=q.top();
        q.pop();
        if(temp.second.first==(1<<(k+1))-1&&temp.second.second==k)
        {
            printf("%lld\n",-temp.first);
            return 0;
        }
        if(mark[temp.second.first][temp.second.second]!=-temp.first)
            continue ;
        play(temp.first,temp.second.first,temp.second.second);
    }
}
