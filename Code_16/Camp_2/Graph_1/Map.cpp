/*
    TASK:Map
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int u[40100],d[40100],r[40100],l[40100],mark[500][500],sti=2e9,stj=2e9;
void play(int k,int i,int j){
    sti=min(sti,i);
    stj=min(stj,j);
    if(u[k] && mark[i-1][j]==-1){
        mark[i-1][j]=u[k];
        play(u[k],i-1,j);
    }
    if(d[k] && mark[i+1][j]==-1){
        mark[i+1][j]=d[k];
        play(d[k],i+1,j);
    }
    if(r[k] && mark[i][j+1]==-1){
        mark[i][j+1]=r[k];
        play(r[k],i,j+1);
    }
    if(l[k] && mark[i][j-1]==-1){
        mark[i][j-1]=l[k];
        play(l[k],i,j-1);
    }
}
int main()
{
    int n,m,a,b;
    char c;
    int k;
    scanf("%d %d",&n,&m);
    k=(m*n)-1;
    while(k--){
        scanf("%d %c %d",&a,&c,&b);
        if(c=='U'){
            d[a]=b;
            u[b]=a;
        }else{
            r[a]=b;
            l[b]=a;
        }
    }
    memset(mark,-1,sizeof mark);
    mark[n][m]=0;
    play(0,n,m);
    for(int i=sti;i<sti+n;i++){
        for(int j=stj;j<stj+m;j++){
            printf("%d ",mark[i][j]);
        }
        printf("\n");
    }
    // for(int i=1;i<=n*2;i++){
    //     for(int j=1;j<=m*2;j++){
    //         printf("%d ",mark[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}
