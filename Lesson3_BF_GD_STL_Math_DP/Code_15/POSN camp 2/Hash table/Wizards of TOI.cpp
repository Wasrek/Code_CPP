/*
    TASK:Wizards of TOI
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
#define hashsize 5000011
int hashtable[hashsize],keep[2][hashsize],xt,yt;
int x[4][1510],y[4][1510],i,j,r,s,t,n,p,q;
int main()
{
    scanf("%d %d %d",&xt,&yt,&n);
    for(i=0; i<4; i++)
    {
        for(j=0; j<n; j++)
            scanf("%d %d",&x[i][j],&y[i][j]);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            r=x[0][i]+x[1][j],s=y[0][i]+y[1][j];
            t=((r+(3*s)%hashsize)%hashsize+hashsize)%hashsize;//Hash Function
            while(hashtable[t]!=0)
            {
                t++;
                t%=hashsize;
            }
            hashtable[t]=(1500*i)+j+1;
            keep[0][t]=r,keep[1][t]=s;
        }
    }
    for(i=0; i<n; i++) //Lom
    {
        for(j=0; j<n; j++) //Fire
        {
            r=xt-(x[2][i]+x[3][j]),s=yt-(y[2][i]+y[3][j]);
            t=((r+(3*s)%hashsize)%hashsize+hashsize)%hashsize;
            while(hashtable[t]!=0){
            if(keep[0][t]==r && keep[1][t]==s)
            {
                p=hashtable[t]-1;
                printf("%d %d\n",x[0][p/1500],y[0][p/1500]);
                printf("%d %d\n",x[1][p%1500],y[1][p%1500]);
                printf("%d %d\n",x[2][i],y[2][i]);
                printf("%d %d\n",x[3][j],y[3][j]);
                return 0;
            }
            t++;t%=hashsize;
            }
        }
    }
    return 0;
}
/*
-2 2
2
1 2 -2 10
-6 -6 -1 3
-1 -2 -6 -5
5 -4 7 0
*/
