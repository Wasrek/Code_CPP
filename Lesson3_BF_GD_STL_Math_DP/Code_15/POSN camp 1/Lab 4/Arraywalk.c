/*
    TASK:Arraywalk
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int k[50][50];
int main()
{
    int x,y,n,m;
    scanf(" %d %d",&n,&m);
    for(x=0;x<n;x++)
    {
        for(y=0;y<m;y++)
        {
            scanf(" %d",&k[x][y]);
        }
    }
    for(x=0;x<n;x++)
    {
        for(y=0;y<m;y++)
        {
            printf("%d ",k[x][y]);
        }
    }printf("\n");
    for(x=n-1;x>=0;x--)
    {
        for(y=m-1;y>=0;y--)
        {
            printf("%d ",k[x][y]);
        }
    }printf("\n");
    for(y=0;y<m;y++)
    {
        for(x=0;x<n;x++)
        {
            printf("%d ",k[x][y]);
        }
    }printf("\n");
    for(y=m-1;y>=0;y--)
    {
        for(x=n-1;x>=0;x--)
        {
            printf("%d ",k[x][y]);
        }
    }


    return 0;
}
