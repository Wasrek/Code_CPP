#include<stdio.h>
void main()
{
   int x,y,z,a;
   printf("Enter number :");
   scanf(" %d",&x);
   for(y=0;y<x;y++)
   {
       a=x-y;
      for(z=0;z<y;z++)
      {
         printf(" ");
      }
      for(z=0;z<a;z++)
      {
         printf("*");
      }
      printf("\n");
   }
}
