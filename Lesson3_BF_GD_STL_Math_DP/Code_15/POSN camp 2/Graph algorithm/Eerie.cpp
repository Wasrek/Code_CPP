/*
    TASK:Eerie
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int d[250][250],x[20100],y[20100],z[20100];
int main(){
    int q,n,m,i,j,k,s,e,w,p,ch;
    scanf("%d",&q);
    while(q--){
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            d[i][j]=1<<25;
        }
    }
    for(i=1;i<=n;i++)
        d[i][i]=0;
    while(m--){
        scanf("%d %d %d",&s,&e,&w);
        d[s][e]=d[e][s]=w;
    }
    scanf("%d",&p);
    for(i=0;i<p;i++)
        scanf("%d %d %d",&x[i],&y[i],&z[i]);
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            for(k=0,ch=1;k<p;k++){
                s=x[k],e=y[k];
                if(min(d[s][e],min(d[s][i]+d[j][e],d[s][j]+d[i][e]))!=z[k]){
                    ch=0;break;
                }
            }
            if(ch){
                printf("%d %d\n",i,j);
                goto jump;
            }
        }
    }
        jump : ;
    }
    return 0;
}


