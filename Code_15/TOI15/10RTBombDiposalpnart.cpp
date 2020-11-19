#include<bits/stdc++.h>
using namespace std;
struct A
{
    int st,v,w,bit,num;
};
int dist[20][20][70000];
int a[20];
deque<A>de;
int main()
{
    int q,n,p,i,st,v,w,bit,num,u,ch=0,j,stt,bitt,numm,k;
    scanf("%d",&q);
    while(q--)
    {
        memset(dist,-1,sizeof dist);
        ch=0;
        scanf("%d %d",&n,&p);
        for(i=0; i<=n; i++)
        {
            for(j=0; j<=n; j++)
            {
                for(k=0; k<=(1<<n+1); k++)
                {
                    dist[i][j][k]=1<<30;
                }
            }
        }
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1; i<=n; i++)
        {
            if(a[i]==1)
                de.push_back({1,i,0,0,0});
            else
            {
                de.push_back({0,i,0,0,0});
            }
        }
        while(!de.empty())
        {
            u=de.front().v,st=de.front().st,w=de.front().w,bit=de.front().bit,num=de.front().num;
            de.pop_front();
            if(st==n)
            {
                printf("%d\n",w);
                break;
            }
            if(bit&(1<<(st+1)))
            {
                if(w<dist[st+1][u][bit^(1<<(st+1))])
                {
                    dist[st+1][u][bit^(1<<(st+1))]=w;
                    de.push_front({st+1,u,w,bit^(1<<(st+1)),num-1});
                }
            }
            if(num<p&&(bit&(1<<a[u]))==0&&st<a[u])
            {
                if(w<dist[st][u][bit|(1<<a[u])])
                {
                    dist[st][u][bit|(1<<a[u])]=w;
                    de.push_front({st,u,w,bit|(1<<a[u]),num+1});
                }
            }
            if(u+1<=n)
            {
                if(st+1==a[u+1])
                {
                    if(w+1<dist[st+1][u+1][bit])
                    {
                        dist[st+1][u+1][bit]=w+1;
                        de.push_back({st+1,u+1,w+1,bit,num});
                    }
                }
                else
                {
                    if(w+1<dist[st][u+1][bit])
                    {
                        dist[st][u+1][bit]=w+1;
                        de.push_back({st,u+1,w+1,bit,num});
                    }
                }
            }
            if(u-1>=1)
            {
                numm=num;
                bitt=bit;
                if(st+1==a[u-1])
                {
                    if(w+1<dist[st+1][u-1][bit])
                    {
                        dist[st+1][u-1][bit]=w+1;
                        de.push_back({st+1,u-1,w+1,bit,num});
                    }
                }
                else
                {
                    if(w+1<dist[st][u-1][bit])
                    {
                        dist[st][u-1][bit]=w+1;
                        de.push_back({st,u-1,w+1,bit,num});
                    }
                }
            }
        }
        while(!de.empty())
            de.pop_back();
        if(ch)
            break;
        //printf("e");
    }
    return 0;
}
