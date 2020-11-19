/*
    TASK:FC_COI Board Game!
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int jj,b,p,i,j,dis;
    bool operator<(const A &o)const{
    return dis>o.dis;
    }
};
char a[510][510];
int dis[2][2][2][510][510],di[]={0,0,-1,1},dj[]={1,-1,0,0};
priority_queue< A >q;
int main(){
    int n,m,i,j,b,p,ii,jj,w,k,iii,jjj,tj,tb,tp;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
            dis[0][0][0][i][j]=1<<30;
            dis[1][0][0][i][j]=1<<30;
            dis[0][1][0][i][j]=1<<30;
            dis[0][0][1][i][j]=1<<30;
            dis[1][1][0][i][j]=1<<30;
            dis[0][1][1][i][j]=1<<30;
            dis[1][0][1][i][j]=1<<30;
            dis[1][1][1][i][j]=1<<30;
            if(a[i][j]=='S'){
                dis[0][0][0][i][j]=0;
                q.push({0,0,0,i,j,0});
            }
        }
    }
    while(!q.empty()){
        j=q.top().jj;
        b=q.top().b;
        p=q.top().p;
        w=q.top().dis;
        ii=q.top().i;
        jj=q.top().j;
        q.pop();
        if(a[ii][jj]=='E'){
            printf("%d\n",w);
            return 0;
        }
        for(k=0;k<4;k++){
            iii=ii+di[k];
            jjj=jj+dj[k];
            tj=j,tb=b,tp=p;
            if(iii<1 || iii>n || jjj<1 || jjj>m)continue;
            if(a[iii][jjj]=='#')continue;
            if(a[iii][jjj]=='J' && tj==0)continue;
            if(a[iii][jjj]=='B' && tb==0)continue;
            if(a[iii][jjj]=='P' && tp==0)continue;
            if(a[iii][jjj]=='j')tj=1;
            if(a[iii][jjj]=='b')tb=1;
            if(a[iii][jjj]=='p')tp=1;
            if(dis[tj][tb][tp][iii][jjj]<=w+1)continue;
            dis[tj][tb][tp][iii][jjj]=w+1;
            q.push({tj,tb,tp,iii,jjj,w+1});
        }
    }
    printf("-1\n");
}
