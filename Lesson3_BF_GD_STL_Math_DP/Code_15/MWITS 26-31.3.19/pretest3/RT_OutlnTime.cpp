/*
    TASK:RT_OutlnTime
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,t,h;
};
queue< A > q;
char a[50][50];
int dis[50][50],di[4]={0,0,-1,1},dj[4]={-1,1,0,0},mark[50][50];
int main(){
    int Q,r,c,t,i,j,si,sj,ei,ej,ti,tj,tt,k,ii,jj,th,cou,all,mm;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d %d %d",&r,&c,&t);
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                scanf(" %c",&a[i][j]);
            }
        }
        scanf("%d %d %d %d",&si,&sj,&ei,&ej);
        q.push({si,sj,0,1});
        memset(dis,127,sizeof dis);
        dis[si][sj]=1;mark[si][sj]=1;
        cou=1;
        while(!q.empty()){
            ti=q.front().i;
            tj=q.front().j;
            tt=q.front().t;
            th=q.front().h;
            q.pop();
            //printf("%d %d %d",ti,tj,th);
            //dis[ti][tj]=max(dis[ti][tj],th);
            //if(ti==ei && tj==ej)break;
            //if(tt>=t)continue;
            for(k=0;k<4;k++){
                ii=ti+di[k];
                jj=tj+dj[k];
                if(mark[ii][jj])continue;
                if(a[ii][jj]=='#')continue;
                if(ii<1 || ii>r || jj<1 || jj>c)continue;
                mark[ii][jj]=1,cou++;
                if(th+1<dis[ii][jj]){
                dis[ii][jj]=th+1;
                q.push({ii,jj,0,th+1});
                }
            }
        }
        if(!mark[ei][ej])printf("-1\n");
        else{
        if(t<dis[ei][ej]-1)printf("-1\n");
        else{
        mm=t-dis[ei][ej]+1;
        //printf("test: %d %d %d\n",dis[ei][ej],cou,mm);
        cou-=dis[ei][ej];
        if(cou*2>mm){
            dis[ei][ej]+=mm/2;
            printf("%d\n",dis[ei][ej]);
        }else{
            dis[ei][ej]+=cou;
            printf("%d\n",dis[ei][ej]);
        }
        }
        }
        memset(dis,0,sizeof dis);
        memset(mark,0,sizeof mark);
    }
}
/*
3
5 8 9
#..#..#.
.#...##.
##.##..#
...##.##
##.#..##
4 3 2 4
3 5 2
.....
.####
.....
3 3 1 3
4 5 100
.....
.####
...#.
#.##.
3 3 1 3
*/
