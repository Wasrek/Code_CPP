/*
    TASK:RC_Ultimate Again
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int b[1010][1010],mark[1010][1010],di[]={-1,-1,-1},dj[]={-1,0,1},dii[]={1,1,1},djj[]={-1,0,1};
void mar(int i,int j,int state){
    if(state==0)return ;
    mark[i][j]=1;
    int k,ii,jj;
    for(k=0;k<3;k++){
        ii=i+di[k];
        jj=j+dj[k];
        mar(ii,jj,state-1);
    }
}
void mard(int i,int j,int state){
    if(state==0)return ;
    //printf("\n%d %d\n",i,j);
    mark[i][j]=1;
    int k,ii,jj;
    for(k=0;k<3;k++){
        ii=i+dii[k];
        jj=j+djj[k];
        mard(ii,jj,state-1);
    }
}
int main(){
    int n,m,i,j,ma=0,ii,jj;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='#')b[i][j]=-1;
            else b[i][j]=1;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(b[i][j]==-1)continue;
            if(b[i-2][j]>0 && b[i-1][j]>0 && b[i-1][j+1]>0 && b[i-1][j-1]>0 && i>=2){
                b[i][j]=min(b[i-2][j],min(b[i-1][j],min(b[i-1][j-1],b[i-1][j+1])))+1;
                if(ma<b[i][j]){
                    ma=b[i][j];
                    ii=i,jj=j;
                }
            }
        }
    }
//    for(i=1;i<=n;i++){
//        for(j=1;j<=m;j++){
//            if(b[i][j]==-1)printf("# ");
//            else printf("%d ",b[i][j]);
//        }
//        printf("\n");
//    }
    int iii,jjj;
    iii=ii-((ma-1)*2);
    mar(ii,jj,ma);
    mard(iii,jj,ma-1);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(mark[i][j])printf("x");
            else printf("%c",a[i][j]);
        }
        printf("\n");
    }
}
/*
10 10
..#....#..
..........
.#....#...
.....#....
..........
.........#
....#.....
..#..#....
..........
.......#..
*/
