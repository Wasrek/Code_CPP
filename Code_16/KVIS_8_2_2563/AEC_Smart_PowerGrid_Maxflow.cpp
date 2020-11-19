/*
    TASK:AEC_Smart_PowerGrid_MF
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int g[110][110],dis[110],p[110],n,m,s,t;
queue< int > bfs;
bool play(){// check if there is a augmented path 
    memset(dis,-1,sizeof dis);
    dis[s]=0;
    bfs.push(s);
    while(!bfs.empty()){
        int now=bfs.front();
        bfs.pop();
        for(int i=1;i<=n;i++){
            if(g[now][i]>0 && dis[i]==-1){
                dis[i] = dis[now]+1;
                p[i]=now;
                bfs.push(i);
            }
        }
    }
    return dis[t]>0;
}
int maxflow(int u,int flow){
    if(u==s) return flow;
    flow= maxflow(p[u],min(flow,g[p[u]][u]));
    g[p[u]][u]-=flow;
    g[u][p[u]]+=flow;
    return flow;
}
int main()
{
    int u,v,w,ans=0;
    scanf("%d %d %d %d",&n,&m,&s,&t);
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        g[u][v]=w;
    }
    while(play()){
        ans+=maxflow(t,1<<28);
    }
    printf("%d\n",ans);
    return 0;
}
/*
4 5
1 4
1 2 15
2 4 10
3 4 19
2 3 5
1 3 12
*/