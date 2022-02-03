/*
    TASK:Eerie
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dis[2010][2010],x[5010],y[5010],z[5010];
int main(){
    int q,i,j,k,n,m,u,v,w,p,ch,s,e;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(i!=j)
                dis[i][j]=1<<20;
            }
        }
        for(i=1;i<=m;i++){
            scanf("%d %d %d",&u,&v,&w);
            dis[u][v]=dis[v][u]=w;
        }
        for(k=1;k<=n;k++){
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
                }
            }
        }
        scanf("%d",&p);
        for(i=1;i<=p;i++){
            scanf("%d %d %d",&x[i],&y[i],&z[i]);
        }
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                for(k=1,ch=1;k<=p;k++){
                    s=x[k],e=y[k];
                if(min(dis[s][e],min(dis[s][i]+dis[j][e],dis[s][j]+dis[i][e]))!=z[k]){
                    ch=0;break;
                }
                }
                if(ch){
                    printf("%d %d\n",i,j);
                    goto bye ;
                }
            }
        }
        bye : ;
    }
    return 0;
}
