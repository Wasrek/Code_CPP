/*
    TASK:Mobile Find
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
#include<stdlib.h>
int a[50][50];
int main()
{
    int q,r,c,Max,ansi,ansj,i,j;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&r,&c);
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        Max=-1000,ansi=ansj=1;
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                if(j+1 <= c&&abs(a[i][j]-a[i][j+1]) <= 10 && (a[i][j]+a[i][j+1])>Max)
                {
                    Max=a[i][j]+a[i][j+1],ansi=i,ansj=j;
                }
                if(i+1 <= r&&abs(a[i][j]-a[i+1][j]) <= 10 && (a[i][j]+a[i+1][j])>Max)
                {
                    Max=a[i][j]+a[i+1][j],ansi=i,ansj=j;
                }
            }
        }
        printf("%d %d\n",ansi,ansj);
    }return 0;
}
