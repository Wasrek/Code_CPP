/*
    TASK:BUU Opposite
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
};
struct B{
    int i,j,ii,jj,w;
};
char a[35][35];
int dis[35][35][35][35],ma[35][35],di[]={1,-1,0,0},dj[]={0,0,1,-1},mark[35][35][35][35];
queue< A > q;
queue< B > qq;
int main()
{
    int qu,n,m,ai,aj,bi,bj,ti,tj,tw,ii,jj,mi,qqq;
    scanf("%d",&qqq);
    for(int qu=qqq;qu>=1;qu--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf(" %s",a[i]+1);
        }
        memset(dis,127,sizeof dis);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]!='#'){
                    if(a[i][j]=='A') ai=i,aj=j;
                    if(a[i][j]=='B') bi=i,bj=j;
                    dis[i][j][i][j]=0;
                    q.push({i,j,0});
                    while(!q.empty()){
                        ti=q.front().i;
                        tj=q.front().j;
                        tw=q.front().w;
                        q.pop();
                        // printf("--------------------------\n");
                        // printf("%d %d %d %d\n",i,j,i,j);
                        for(int k=0;k<4;k++){
                            ii=ti+di[k];
                            jj=tj+dj[k];
                            // printf("%d %d %d %d\n",i,j,ii,jj);
                            if(ii<1 || ii>n || jj<1 || jj>m) continue;
                            if(dis[i][j][ii][jj]<=tw+1) continue;
                            if(a[ii][jj]=='#')continue;
                            // printf("Hi\n");
                            dis[i][j][ii][jj]=tw+1;
                            q.push({ii,jj,tw+1});
                        }
                    }
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         printf("%d ",dis[2][1][i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("%d\n",dis[2][1][2][5]);
        mi=dis[ai][aj][bi][bj];
        if(mi==dis[0][0][0][0]){
            printf("-1 0\n");
            continue;
        }
        int i,j,ii,jj,ni,nj,nii,njj,ans;
        ans=0;
        qq.push({ai,aj,bi,bj,0});
        mark[ai][aj][bi][bj]=qu;
        while(!qq.empty()){
            i=qq.front().i;
            j=qq.front().j;
            ii=qq.front().ii;
            jj=qq.front().jj;
            tw=qq.front().w;
            qq.pop();
            // printf("------------------------");
            // printf("%d %d %d %d\n",i,j,ii,jj);
            for(int k=0;k<4;k++){
                ni=i+di[k];
                nj=j+dj[k];
                nii=ii-di[k];
                njj=jj-dj[k];
                if(ni<1 || ni>n || nj<1 || nj>m){
                    ni=i,nj=j;
                }
                if(a[ni][nj]=='#'){
                    ni=i,nj=j;
                }
                if(nii<1 || nii>n || njj<1 || njj>m){
                    nii=ii,njj=jj;
                }
                if(a[nii][njj]=='#'){
                    nii=ii,njj=jj;
                }
                // printf("%d %d %d %d %d\n",ni,nj,nii,njj,mark[ni][nj][nii][njj]);
                // if(dis[ni][nj][nii][njj]>=dis[i][j][ii][jj])continue;
                if(mark[ni][nj][nii][njj]==qu) continue;
                mark[ni][nj][nii][njj]=qu;
                if(dis[ni][nj][nii][njj]<mi)ans=tw+1,mi=dis[ni][nj][nii][njj];
                qq.push({ni,nj,nii,njj,tw+1});
            }
        }
        printf("%d %d\n",mi,ans);
    }
    return 0;
}