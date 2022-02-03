/*
    TASK:Circular Maze
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[120][120],mark[120][120];
int r,c,di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
void dfs(int i,int j){
   int k,l,m,nexti,nextj;
   for(k=0;k<4;k++){
    nexti=(i+di[k]+r)%r,nextj=(j+dj[k]+c)%c;
    if(a[nexti][nextj]=='#')continue;
    if(mark[nexti][nextj])continue;
    if(a[nexti][nextj]=='E'){
        for(l=0;l<r;l++){
            for(m=0;m<c;m++)
                printf("%c",a[l][m]);
            printf("\n");
        }
        exit(0);
    }
    char temp=a[nexti][nextj];
    a[nexti][nextj]='x';
    mark[nexti][nextj]=1;
    dfs(nexti,nextj);
    a[nexti][nextj]=temp;//backtracking

   }
}
int main()
{
   int i,j,sti,stj;
   scanf("%d %d",&r,&c);
   for(i=0;i<r;i++){
    for(j=0;j<c;j++){
        scanf(" %c",&a[i][j]);
        if(a[i][j]=='S')
            sti=i,stj=j;
    }
   }
   mark[sti][stj]=1;
   dfs(sti,stj);
   return 0;
}
/*
6 12
####.#..####
.S.#..#.#E##
#.#...#.#..#
..##..#..#..
.#.#.#.###.#
.........###
*/
