/*
    TASK:Loop practice
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int main()
{
    int n,x;
    scanf(" %d",&n);
    for(x=1;x<=n;x++)
    {
    printf("%d ",x);
    }

    printf("\n");
    x=n;

    while(x>=1)
    {printf("%d ",x);x--;}

    printf("\n");
    x=1;

    do{
       if(x%2==0){
       printf("%d ",x);}x++;
    }while(x<=n);

    printf("\n");

     for(x=n;x>=1;x--)
    {
       if(x%2==0){printf("%d ",x);}
    }

    printf("\n");
    x=1;

    while(x<=n)
    {if(x%2==1)printf("%d ",x);x++;}

    printf("\n");
    x=n;

    do{
    if(x%2==1){
    printf("%d ",x);
    }
    x--;
    }while(x>=1);
    return 0;
}
