#include <stdio.h>
int main ()
{
    int mynum[5] = {10, 20, 30, 40, 50};
    int *mypoint;

    int i;
    for(i=0;i<=4;i++) printf("%d ",mynum[i]);
    mypoint = &mynum;
    printf("\n%d\n",mypoint);

    *mypoint = 99;
    for(i=0;i<=4;i++) printf("%d ",mynum[i]);

    printf("\n");
    *mypoint++;
    *mypoint = 88;
    for(i=0;i<=4;i++) printf("%d ",mynum[i]);

    printf("\n");
    mypoint=&mynum;
    *mypoint = 77;
    for(i=0;i<=4;i++) printf("%d ",mynum[i]);

    }
