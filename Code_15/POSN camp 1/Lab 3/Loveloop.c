/*
    TASK:Loveloop
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<stdio.h>
int main()
{
    int n,x,y,z;
    scanf(" %d",&n);
    for(x=1;x<=n;x++)
    {
        for(y=0;y<n;y++)
        {
            printf("%d ",x+y);
        }
        printf("\n");
    }
    for(x=1;x<=n;x++)
    {
        for(y=0;y<n;y++)
        {
            z=x+y;
            if(z>n && z%n!=0)
            {
                z=z%n;
            }
            printf("%d ",z);
        }
        printf("\n");
    }
    return 0;
}
