/*
    TASK:Road Wonder
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
};
A g[1500];
int dis[1010],ans[1010];
int main()
{
    int n,m,k,t,u,v,w,cnt=0;
    scanf("%d %d %d %d",&n,&m,&k,&t);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[++cnt].u=u;
        g[cnt].v=v;
        g[cnt].w=w;
    }
    for(int i=1;i<=k;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[++cnt].u=u;
        g[cnt].v=v;
        g[cnt].w=w*-1;
    }
    int q;
    while(t--){
        scanf("%d",&q);
        for(int i=1;i<=n;i++){
            dis[i]=2e9;
        }
        dis[q]=0;
        for(int i=1;i<=n-1;i++){
            for(int j=1;j<=cnt;j++){
                if(dis[g[j].u]!=2e9 && dis[g[j].u]+g[j].w<dis[g[j].v]){
                    dis[g[j].v]=dis[g[j].u]+g[j].w;
                }
            }
        }
        for(int i=1;i<=n;i++)
            ans[i] = dis[i];
        for(int j=1;j<=cnt;j++){
            if(dis[g[j].u]!=2e9 && dis[g[j].u]+g[j].w<dis[g[j].v]){
                dis[g[j].v]=dis[g[j].u]+g[j].w;
            }
        }
        for(int i=1;i<=n;i++){
            if(ans[i]==dis[i] && dis[i]!=2e9)   printf("%d ",dis[i]);
            else                                printf("-1 ");
        }
        printf("\n");
    }
    return 0;
}
/*
10 5 5 5
1 7 8
2 5 1
3 4 7
5 8 4
5 1 11
10 1 6
10 5 3
10 3 1
9 5 10
5 7 2
2
4 
6
8
10
*/