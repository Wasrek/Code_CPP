/*
    TASK:48_Follow
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,w;
    bool operator <(const A & o)const{
        return w>o.w;
    }
};
struct B{
    int st,en;
};
vector< A > g[1010];
priority_queue< A > h;
int len[1010][1010],dis[1010],way[1010];
B use[1010][1010];
int main()
{
    int q,n,m,s,e,t,p,u,v,w,now;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        scanf("%d %d %d %d",&s,&e,&t,&p);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                len[i][j]=2e9;
                dis[i]=2e9;
                use[i][j].en=-1;
                g[i].clear();
            }
        }
        for(int i=1;i<=p;i++){
            scanf("%d",&way[i]);
        }
        while(m--){
            scanf("%d %d %d",&u,&v,&w);
            len[u][v]=w;
            len[v][u]=w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        for(int i=1;i<p;i++){
            use[way[i]][way[i+1]].en=len[way[i]][way[i+1]]+use[way[i-1]][way[i]].en;
            use[way[i]][way[i+1]].st=use[way[i-1]][way[i]].en;
            // printf("%d ",use[way[i]][way[i+1]]);
        }
        // for(int i=1;i<p;i++){
            // printf("%d ",use[way[i]][way[i+1]].st);
        // }
        // printf("\n");
        for(int i=1;i<p;i++){
            use[way[i]][way[i+1]].en--;
            use[way[i+1]][way[i]]=use[way[i]][way[i+1]];
            // printf("%d ",use[way[i]][way[i+1]].en);
        }
        // printf("\n");
        dis[s]=0;
        h.push({s,t});
        while(!h.empty()){
            u=h.top().i;
            w=h.top().w;
            h.pop();
            // printf("%d %d\n",u,w);
            if(u==e){
                printf("%d\n",w-t+1);
                goto jump;
            }
            for(auto x: g[u]){
                // printf("%d %d %d %d %d\n",u,x.i,x.w,use[u][x.i].st,use[u][x.i].en);
                if(use[u][x.i].en==-1 || (use[u][x.i].en!=-1 && (w<use[u][x.i].st || w>=use[u][x.i].en))){
                    if(dis[x.i]<=w+x.w) continue;
                    // printf("no\n");
                    dis[x.i]=w+x.w;
                    h.push({x.i,dis[x.i]});
                }else{
                    now=use[u][x.i].en;
                    if(dis[x.i]<=x.w+now)continue;
                    // printf("yes\n");
                    dis[x.i]=x.w+now;
                    h.push({x.i,dis[x.i]});
                }
            }
        }
        jump:;
        while(!h.empty()) h.pop();
    }
    return 0;
}