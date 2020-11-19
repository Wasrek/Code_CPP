/*
    TASK:Temperature is Rising
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int a[100][100];
int r,Max;
void play(int x,int y){
    if(a[x][y]!=100){
   if(a[x][y]>Max){Max=a[x][y];}
   a[x][y]=100;
   if(x-1>=0 )play(x-1,y);
   if(y-1>=0 )play(x,y-1);
   if(x+1<r )play(x+1,y);
   if(y+1<r )play(x,y+1);}
}
int main()
{
    int i,j,x,y;
    scanf("%d",&r);
    scanf("%d %d",&y,&x);
    for(i=0;i<r;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    x=x-1;y=y-1;
    Max=a[x][y];
    //printf("%d",Max);
    play(x,y);
    printf("%d",Max);

    return 0;
}
/*
4
2 1
100 1 3 8
0 2 1 4
2 3 5 100
0 8 8 100
*/
/*
5
4 2
0 1 100 100 0
100 2 3 1 1
100 100 4 5 100
8 7 100 6 100
7 100 100 100 9*/
