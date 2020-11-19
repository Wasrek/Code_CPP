#include<bits/stdc++.h>
using namespace std;
vector <int> re[1005];
int in[1005],temp[1005],mark[1005];
queue <int> q;
void play(int v)
{
    mark[v]=1;
    for(int i=0;i<re[v].size();i++)
    {
        temp[re[v][i]]--;
        if(!temp[re[v][i]]&&!mark[re[v][i]])
            play(re[v][i]);
    }
}
int main()
{
    //freopen("20.in","r",stdin);
    //freopen("20.sol","w",stdout);
    int n,m,i,a,b,t,p,ch;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&a,&b);
        re[b].push_back(a);
        in[a]++;
    }
    scanf("%d",&t);
    while(t--)
    {
        ch=0;
        for(i=1;i<=n;i++)
            temp[i]=in[i];
        scanf("%d",&p);
        memset(mark,0,sizeof(mark));
        for(i=1;i<=n;i++)
            if(!temp[i]&&!mark[i])
                play(i);
        while(p--)
        {
            scanf("%d",&a);
            if(!mark[a])
                play(a);
        }
        for(i=1;i<=n;i++)
            if(!mark[i])
            {
                ch=1;
                printf("%d ",i);
            }
        if(!ch)
            printf("-1");
        printf("\n");
    }
    return 0;
}
