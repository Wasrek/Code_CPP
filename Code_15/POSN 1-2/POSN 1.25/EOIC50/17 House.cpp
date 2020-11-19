/*
    TASK: House
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int r,c,k,f[1500][1500],p[1500][1500];
int main()
{
    int i,j,Max=0,x,pl,hi,hj,hpl;
    scanf("%d %d %d",&r,&c,&k);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&f[i][j]);
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            pl=0;
            for(x=1;x<=k;x++){
            if(x%2==1){
            if(i-x>=0)pl+=(f[i-x][j]*(-1));
            if(i+x<r)pl+=(f[i+x][j]*(-1));
            if(j-x>=0)pl+=(f[i][j-x]*(-1));
            if(j+x<c)pl+=(f[i][j+x]*(-1));
            }else{
            if(i-x>=0)pl+=f[i-x][j];
            if(i+x<r)pl+=f[i+x][j];
            if(j-x>=0)pl+=f[i][j-x];
            if(j+x<c)pl+=f[i][j+x];
            }
            }
         p[i][j]=f[i][j]+pl;
        if(p[i][j]>Max){Max=p[i][j];hi=i;hj=j;hpl=pl;}
        }
        }
    printf("%d\n",Max);
}
/*
5 4 2
2 2 3 5
3 2 4 0
5 3 1 2
0 2 0 1
3 2 1 5
*/
