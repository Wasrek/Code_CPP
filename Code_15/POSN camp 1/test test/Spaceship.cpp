/*
    TASK:Spaceship
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int At[15][5],have[15][5],n,mark[15],M,Min;
void play(int x,int y,int z,int m,int k,int c,int sum){
   int i,mm,kk,cc,nowsum;
   for(i=0;i<M;i++){
      if(mark[i]!=1){
        mark[i]=1;
        mm=m+have[i][0],kk=k+have[i][1],cc=c+have[i][2];
        nowsum=sum+((x-At[i][0])*(x-At[i][0]))+((y-At[i][1])*(y-At[i][1]))+((z-At[i][2])*(z-At[i][2]));
        if(mm>=n&&kk>=n&&cc>=n){
            if(nowsum<Min) Min=nowsum;
            mark[i]=0;
            continue;
        }
        play(At[i][0],At[i][1],At[i][2],mm,kk,cc,nowsum);
        mark[i]=0;
        }
   }
}
int main()
{
    int x,y,z,i;
    scanf("%d %d %d %d %d",&n,&x,&y,&z,&M);
    for(i=0;i<M;i++){
        scanf("%d %d %d",&At[i][0],&At[i][1],&At[i][2]);
        scanf("%d %d %d",&have[i][0],&have[i][1],&have[i][2]);
    }
    Min=2000000000;
    play(x,y,z,0,0,0,0);
    printf("%d\n",Min);
    return 0;
}
/*
1
0 0 0
2
10 0 0
2 5 7
0 10 0
0 3 9
*/
