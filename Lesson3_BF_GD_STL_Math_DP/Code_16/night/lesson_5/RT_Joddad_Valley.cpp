/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
double dis[220][220],ma[220];
char opr[10];
struct A{
    int u;
    double w,v;
    bool operator<(const A & o) const{
        return w>o.w;
    }
};
priority_queue< A > h;
int main()
{
    int n,m,q,u,v,s,e;
    double w,ve,c;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=LONG_LONG_MAX;
        }
        dis[i][i]=0.0;
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d %lf",&u,&v,&w);
        dis[u][v]=min(dis[u][v],min(w,dis[v][u]));
        dis[v][u]=dis[u][v];
    }
    while(q--){
        scanf(" %s",opr+1);
        if(opr[1]=='t'){
            scanf("%d %d %lf %lf",&s,&e,&ve,&c);
            while(!h.empty())h.pop();
            for(int i=1;i<=n;i++) ma[i]=LONG_LONG_MAX;
            ma[s]=0;
            h.push({s,0.0,ve});
            while(!h.empty()){
                u=h.top().u;
                w=h.top().w;
                ve=h.top().v;
                // printf("%d %.2lf %.2lf\n",u,v,ve);
                h.pop();
                if(u==e){
                    printf("%.2lf\n",w);
                    goto her;
                }
                if(ve<=0) continue;
                for(int i=1;i<=n;i++){
                    if(ma[i]<=w+(dis[u][i]/ve) || dis[u][i]==LONG_LONG_MAX) continue;
                    // printf("- %d %.2lf\n",i,dis[u][i]);
                    ma[i]=w+(dis[u][i]/ve);
                    h.push({i,ma[i],ve-(dis[u][i]*c)});
                }
            }
            printf("IMPOSSIBLE\n");
            her:;
        }else if(opr[1]=='a'){
            scanf("%d %d",&u,&m);
            for(int i=1;i<=m;i++){
                scanf("%d %lf",&v,&w);
                dis[u][v]=min(dis[u][v],min(w,dis[v][u]));
                dis[v][u]=dis[u][v];
            }
        }else{
            scanf("%d",&u);
            for(int i=1;i<=n;i++){
                dis[u][i]=dis[i][u]=LONG_LONG_MAX;
            }
            dis[u][u]=0;
        }
    }
    return 0;
}
/*
5 10 8
1 2 5.0
1 1 5.5
3 1 6.0
1 3 7.0
2 1 3.0
2 2 9.5
3 3 8.5
4 4 10.0
5 5 11.0
1 2 5.5
travel 2 3 10.0 1.0
travel 2 4 6.0
destroy 4
add 4 1
3 15.5
travel 1 4 3.5 0.1
destroy 2
add 2 3
1 1.0
3 3.0
5 5.0
travel 4 5 1.0 0.2
*/