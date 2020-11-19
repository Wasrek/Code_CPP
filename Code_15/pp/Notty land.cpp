#include<bits/stdc++.h>
using namespace std;
int p[100005],coun;
vector <int> pa[100005],re[100005];
int mark1[100005],mark2[100005];
stack <int> sta;
void play1(int v)
{
    if(mark1[v])
        return ;
    mark1[v]=1;
    for(int i=0;i<pa[v].size();i++)
        play1(pa[v][i]);
    sta.push(v);
}
void play2(int v)
{
    if(mark2[v])
        return ;
    mark2[v]=1;
    p[v]=coun;
    for(int i=0;i<re[v].size();i++)
        play2(re[v][i]);
}
int main()
{
    int n,m,q,i,a,b;
    scanf("%d %d %d",&n,&m,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        while(a--)
        {
            scanf("%d",&b);
            pa[i].push_back(b);
            re[b].push_back(i);
        }
    }
    for(i=1;i<=n;i++)
    {
        if(mark1[i])
            continue ;
        play1(i);
    }
    while(!sta.empty())
    {
        if(!mark2[sta.top()])
            play2(sta.top());
        sta.pop();
        coun++;
    }
    while(q--)
    {
        scanf("%d %d",&a,&b);
        if(p[a]==p[b])
            printf("yes\n");
        else
            printf("no\n");
    }
}
