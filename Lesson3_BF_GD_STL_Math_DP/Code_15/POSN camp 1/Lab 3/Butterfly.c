/*
    TASK:Butterfly
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int main()
{
    int n,d,s;
    scanf(" %d",&n);
    s=n;
    n=(2*n)-1;
    d=((n-1)*2)-1;
    int x,y,p;
    for(x=2;x<n;x+=2)
    {
      for(y=1;y<=(x/2);y++)
      {
          printf("*");
      }
      for(y=0;y<(n-x);y++)
      {
          printf("-");
      }
        for(y=1;y<=(x/2);y++)
      {
          printf("*");
      }
      printf("\n");
    }
    for(x=0;x<n;x++)
    {
        printf("*");
    }
    printf("\n");

    for(x=n-1;x>=2;x-=2)
    {
      for(y=1;y<=(x/2);y++)
      {
          printf("*");
      }
      for(y=0;y<(n-x);y++)
      {
          printf("-");
      }
        for(y=1;y<=(x/2);y++)
      {
          printf("*");
      }
      printf("\n");
    }

    return 0;
}
