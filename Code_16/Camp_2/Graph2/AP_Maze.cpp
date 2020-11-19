/*
    TASK:AP_Maze
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,t,li,lj;
};
queue< A > q;
char a[310][310];
int ma[5][310][310];
int dis[5][310][310],di[]={-1,1,0,0},dj[]={0,0,1,-1};
int main()
{
    int Q,n,m,si,sj,ei,ej;
    scanf("%d",&Q);
    while(Q--){
        memset(ma,0,sizeof ma);
        while(!q.empty()) q.pop();
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf(" %s",a[i]+1);
            for(int j=1;j<=m;j++){
                dis[0][i][j]=dis[1][i][j]=dis[2][i][j]=dis[3][i][j]=2e9;
                if(a[i][j]=='S'){si=i,sj=j;continue;}
                if(a[i][j]=='E'){ei=i,ej=j;continue;}
                if(a[i][j]=='.' || a[i][j]=='#') continue;
                ma[3][i][j]=ma[2][i][j]=ma[1][i][j]=ma[0][i][j]=-1;
                if(a[i][j]=='|')ma[4][i][j]=1;
                if(a[i][j]=='/')ma[4][i][j]=2;
                if(a[i][j]=='-')ma[4][i][j]=3;
                if(a[i][j]=='\\')ma[4][i][j]=4;
            }
        }
        int ii,jj;
        for(int k=0;k<4;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(ma[4][i][j]){
                        ma[k][i][j]=((ma[4][i][j]+k-1)%4)+1;
                        if(ma[k][i][j]==1){
                            ii=i+1;
                            jj=j;
                            while(ii>=1 && jj>=1 && ii<=n && jj<=m && !ma[4][ii][jj] && a[ii][jj]!='#' && a[ii][jj]!='E'){
                                ma[k][ii][jj]=ma[k][i][j];
                                ii++;
                            }
                            ii=i-1;
                            jj=j;
                            while(ii>=1 && jj>=1 && ii<=n && jj<=m && !ma[4][ii][jj] && a[ii][jj]!='#' && a[ii][jj]!='E'){
                                ma[k][ii][jj]=ma[k][i][j];
                                ii--;
                            }
                        }else
                        if(ma[k][i][j]==2){
                            ii=i+1;
                            jj=j-1;
                            while(ii>=1 && jj>=1 && ii<=n && jj<=m && !ma[4][ii][jj] && a[ii][jj]!='#' && a[ii][jj]!='E'){
                                ma[k][ii][jj]=ma[k][i][j];
                                ii++;
                                jj--;
                            }
                            ii=i-1;
                            jj=j+1;
                            while(ii>=1 && jj>=1 && ii<=n && jj<=m && !ma[4][ii][jj] && a[ii][jj]!='#' && a[ii][jj]!='E'){
                                ma[k][ii][jj]=ma[k][i][j];
                                ii--;
                                jj++;
                            }
                        }else
                        if(ma[k][i][j]==3){
                            ii=i;
                            jj=j+1;
                            while(ii>=1 && jj>=1 && ii<=n && jj<=m && !ma[4][ii][jj] && a[ii][jj]!='#' && a[ii][jj]!='E'){
                                ma[k][ii][jj]=ma[k][i][j];
                                jj++;
                            }
                            ii=i;
                            jj=j-1;
                            while(ii>=1 && jj>=1 && ii<=n && jj<=m && !ma[4][ii][jj] && a[ii][jj]!='#' && a[ii][jj]!='E'){
                                ma[k][ii][jj]=ma[k][i][j];
                                jj--;
                            }
                        }else
                        if(ma[k][i][j]==4){
                            ii=i+1;
                            jj=j+1;
                            while(ii>=1 && jj>=1 && ii<=n && jj<=m && !ma[4][ii][jj] && a[ii][jj]!='#' && a[ii][jj]!='E'){
                                ma[k][ii][jj]=ma[k][i][j];
                                ii++;
                                jj++;
                            }
                            ii=i-1;
                            jj=j-1;
                            while(ii>=1 && jj>=1 && ii<=n && jj<=m && !ma[4][ii][jj] && a[ii][jj]!='#' && a[ii][jj]!='E'){
                                ma[k][ii][jj]=ma[k][i][j];
                                ii--;
                                jj--;
                            }
                        }                        
                    }
                }
            }
        }
        // for(int k=0;k<4;k++){
        //     for(int i=1;i<=n;i++){
        //         for(int j=1;j<=m;j++){
        //             printf("%d ",ma[k][i][j]);
        //         }
        //         printf("\n");
        //     }
        //     printf("\n");
        // }
        dis[0][si][sj]=0;
        q.push({si,sj,0});
        while(!q.empty()){
            int i=q.front().i;
            int j=q.front().j;
            int t=q.front().t;
            // printf("%d %d %d %d %d %d\n",i,j,t,ma[t%4][i][j],q.front().li,q.front().lj);
            q.pop();
            // if(ma[t%4][i][j]) continue;
            if(i==ei && j==ej){
                printf("%d\n",t);
                goto jump;
                break;
            }
            // if(dis[((t+1)%4)][i][j]>t+1 && !ma[((t+1)%4)][i][j]){
            //     dis[((t+1)%4)][i][j]=t+1;
            //     q.push({i,j,t+1,i,j});
            // }
            for(int k=0;k<4;k++){
                int ii=i+di[k];
                int jj=j+dj[k];
                if(ii<1 || jj<1 || ii>n || jj>m) continue;
                if(a[ii][jj]=='#')continue;
                if(ma[((t+1)%4)][ii][jj]) continue;
                if(dis[((t+1)%4)][ii][jj]<=t+1) continue;
                dis[((t+1)%4)][ii][jj]=t+1;
                q.push({ii,jj,t+1,i,j});
            }
        }
        printf("-1\n");
        jump:;
    }
    return 0;
}