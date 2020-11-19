#include<stdio.h>
void main()
{
   int x,y,z,a,b;
   printf("Enter number :");
   scanf(" %d",&x);
   b=2*x;
   for(y=1;y<=x;y++)
   {
       for(z=0;z<y;z++)
       {
         printf("*");
       }
       for(z=0;z<(b-(2*y));z++)
       {
         printf(" ");
       }
       for(z=0;z<y;z++)
       {
         printf("*");
       }
      printf("\n");
   }
}

