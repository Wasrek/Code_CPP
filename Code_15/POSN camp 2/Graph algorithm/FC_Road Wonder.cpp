/*
    TASK:FC_Road Wonder
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
#define INF 2000000000
struct A
{
    int u,v,w;
};
A a[1111];
int dis[2000],temp[2000];
int main()
{
    int n,m,k,t,cnt=0,i,s,j;
    scanf("%d %d %d %d",&n,&m,&k,&t);
    for(i=0; i<m; i++)
        scanf("%d %d %d",&a[cnt].u,&a[cnt].v,&a[cnt].w),cnt++;
    for(i=0; i<k; i++)
        scanf("%d %d %d",&a[cnt].u,&a[cnt].v,&a[cnt].w),a[cnt].w*=-1,cnt++;
    while(t--)
    {
        scanf("%d",&s);
        for(i=1; i<=n; i++)
            dis[i]=INF;
        dis[s]=0;
        for(i=0; i<n-1; i++)
            for(j=0; j<cnt; j++)
                if(dis[a[j].u]!=INF && dis[a[j].u]+a[j].w<dis[a[j].v])
                    dis[a[j].v]=dis[a[j].u]+a[j].w;
        for(i=1;i<=n;i++)
            temp[i]=dis[i];
        for(j=0;j<cnt;j++)
            if(dis[a[j].u]!=INF && dis[a[j].u]+a[j].w<dis[a[j].v])
            dis[a[j].v] = dis[a[j].u]+a[j].w;
        for(i=1;i<=n;i++){
            if(dis[i]!=temp[i] || dis[i]==INF)
                printf("-1\n");
            else printf("%d ",dis[i]);
        }
        printf("\n");
    }

    return 0;
}
