/*
    TASK:Matrix multiplication
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
int a[50][50],b[50][50],c[50][50];
#include<stdio.h>
int main()
{
    int n1,m1,n2,m2,k,sum,j;
    scanf(" %d %d %d %d",&n1,&m1,&n2,&m2);
    if(m1!=n2)
    {
        printf("Can't Multiply.");
        return 0;
    }
    int x,y;
    for(x=0;x<n1;x++)
    {
        for(y=0;y<m1;y++)
        {
            scanf(" %d",&a[x][y]);
        }
    }
    for(x=0;x<n2;x++)
    {
        for(y=0;y<m2;y++)
        {
            scanf(" %d",&b[x][y]);
        }
    }

    for(x=0;x<n1;x++)
    {
        for(y=0;y<m2;y++)
        {
            for(k=0,sum=0;k<m1;k++)
            {
                sum+= a[x][k]*b[k][y];
            } printf("%d ",sum);
        }printf("\n");
    }

    return 0;
}
