/*
    TASK:Sewer
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
queue<PII> bfs;
int mark[200][200];
char a[120][120];
int main(){
    int r,c,i,j,ni,nj,ii;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            scanf(" %c",&a[i][j]),mark[i][j]=100000;
    mark[1][1]=1;
    bfs.push({1,1});
    while(!bfs.empty()){
        ni=bfs.front().first,nj=bfs.front().second;bfs.pop();
        if(nj+1<=c && (a[ni][nj]=='R' || a[ni][nj]=='B') && mark[ni][nj]<mark[ni][nj+1]){
            if(mark[ni][nj+1]==mark[ni][nj]+1){
                printf("%d\n%d %d\n",mark[ni][nj]+1,ni,nj+1);
                return 0;
            }
            mark[ni][nj+1]=mark[ni][nj]+1;
            bfs.push({ni,nj+1});
        }
        if(ni+1<=r && (a[ni][nj]=='D' || a[ni][nj]=='B') && mark[ni][nj]<mark[ni+1][nj]){
            if(mark[ni+1][nj]==mark[ni][nj]+1){
                printf("%d\n%d %d\n",mark[ni][nj]+1,ni+1,nj);
                return 0;
            }
            mark[ni+1][nj]=mark[ni][nj]+1;
            bfs.push({ni+1,nj});
        }
        if(nj-1>=1 &&(a[ni][nj-1]=='R' || a[ni][nj-1]=='B')&& mark[ni][nj]<mark[ni][nj-1]){
            if(mark[ni][nj-1]==mark[ni][nj]+1){
                printf("%d\n%d %d\n",mark[ni][nj]+1,ni,nj-1);
                return 0;
            }
            mark[ni][nj-1]=mark[ni][nj]+1;
            bfs.push({ni,nj-1});
        }
        if(ni-1>=1 &&(a[ni-1][nj]=='D' || a[ni-1][nj]=='B')&& mark[ni][nj]<mark[ni-1][nj]){
            if(mark[ni-1][nj]==mark[ni][nj]+1){
                printf("%d\n%d %d\n",mark[ni][nj]+1,ni-1,nj);
                return 0;
            }
            mark[ni-1][nj]=mark[ni][nj]+1;
            bfs.push({ni-1,nj});
        }
    }
}
/*
4 4
B R D N
D R B D
R R R D
N N N N
*/
